#  Capitalise Each Letter With Some Exceptions In A String
# 
# Input: 
    # String:     "where there is a will, there is a way"
    # Exceptions: {"is", "a"}
# Output:
    # String:     "Where There is a Will, There is a Way" 
# 
def sensible_title_caps(str, no_caps_list = ["is", "a"]):
    words = []  
    for word in str.split():
        if word not in no_caps_list:
            word = word.capitalize()
        words.append(word)
    return " ".join(words)
strop="where there is a will, there is a way"
print(sensible_title_caps(strop))