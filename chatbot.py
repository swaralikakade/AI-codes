import nltk
from nltk.chat.util import Chat, reflections

pairs=[
    [
        r"my name is(.*)",
        ["Hello %1,How are you?"]
    ],
    # Or expression
    [
        r"Hi|Hello|Hey there|Hola",
        ["Hello my name is Hiesenberg"]
    ],
    [
        r"what is your name ?",
        ["I am a bot created by Heisenbergwhat. you can call me crazy!",]
    ],
    [
        r"how are you ?",
        ["I'm doing good How about You ?",]
    ],
    [
        r"sorry (.*)",
        ["Its alright","Its OK, never mind",]
    ],
    [
        r"I am fine",
        ["Great to hear that, How can I help you?",]
    ],
    [
        r"I (.*) good",
        ["Nice to hear that","How can I help you?:)",]
    ],
    [
        r"(.*) age?",
        ["I'm a computer program dude Seriously you are asking me this?",]
    ],
    [
        r"what (.*) want ?",
        ["Make me an offer I can't refuse",]
    ],
    [
        r"(.*) created ?",
        ["Raghav created me using Python's NLTK library ","top secret ;)",]
    ],
    [
        r"(.*) (location|city) ?",
        ['Indore, Madhya Pradesh',]
    ],
    [
        r"how is weather in (.*)?",
        ["Weather in %1 is awesome like always","Too hot man here in %1","Too cold man here in %1","Never even heard about %1"]
    ],
    [
        r"i work in (.*)?",
        ["%1 is an Amazing company, I have heard about it. But they are in huge loss these days.",]
    ],
    [
        r"(.)raining in (.)",
        ["No rain since last week here in %2","Damn its raining too much here in %2"]
    ],
    [
        r"how (.) health(.)",
        ["I'm a computer program, so I'm always healthy ",]
    ],
    [
        r"(.*) (sports|game) ?",
        ["I'm a very big fan of Football",]
    ],
    [
        r"who (.*) sportsperson ?",
        ["Messy","Ronaldo","Roony"]
    ],
    [
        r"who (.*) (moviestar|actor)?",
        ["Brad Pitt"]
    ],
    [
        r"i am looking for online guides and courses to learn data science, can you suggest?",
        ["Crazy_Tech has many great articles with each step explanation along with code, you can explore"]
    ],
    [
        r"quit",
        ["Thank you for using our intelligence services"]
    ],   
]

def chat():
    print("Hey there! I am Heisenberg at your service")
    chat = Chat(pairs,reflections)
    chat.converse()

if __name__== "__main__":
    chat()







'''

bot_name = "College Buddy"

knowledge_base = {
    "what is your name?": [
        f"My name is {bot_name}! Happy to help you out with your College enquiries!"
    ],
    "hello": [
        f"Hello! My name is {bot_name}. Happy to help you out with your College enquiries!"
    ],
    "what are the best colleges from pune?": [
        "COEP",
        "PICT",
        "VIT",
        "CUMMINS",
        "PCCOE"
    ],
    "which are the best engineering branches?": [
        "Computer Engineering",
        "IT Engineering",
        "ENTC Engineering"
    ],
    "what are the top branch cut-offs for coep?": [
        "Computer Engineering : 99.8 percentile",
        "Does not have IT branch",
        "ENTC Engineering: 99.2 percentile",
    ],
    "what are the top branch cut-offs for pict?": [
        "Computer Engineering : 99.4 percentile",
        "IT Engineering : 98.6 percentile",
        "ENTC Engineering: 97.2 percentile",
    ],
    "what are the top branch cut-offs for vit?": [
        "Computer Engineering : 99.8 percentile",
        "IT Engineering: 97.1 percentile",
        "ENTC Engineering: 96.2 percentile",
    ],
    "what are the top branch cut-offs for cummins?": [
        "Computer Engineering : 99.8 percentile",
        "Does not have IT branch",
        "ENTC Engineering: 99.2",
    ],
    "what are the top branch cut-offs for pccoe?": [
        "Computer Engineering : 99.8 percentile",
        "Does not have IT branch",
        "ENTC Engineering: 99.2",
    ],
    "When do college admissions start?": [
        "Admissions generally start around August",
    ],
}

print("College Enquiry Rule Based Chatbot")

def respond(input_str):
    input_str = input_str.lower()
    if input_str in knowledge_base:
        print(input_str)
        responses = knowledge_base[input_str]
        for response in responses:
            print(response)
    else:
        print(input_str)
        print("Question is not present in the knowledge base!")
        answer = input("Could you please enter the appropriate answer for the question below-\nAnswer: ")
        knowledge_base[input_str] = [answer]
        print("Answer added successfully!")

while True:
    user_input = input("You: ")
    if user_input.lower() == 'quit':
        print("Thank you for using the Chatbot")
        break
    respond(user_input)

'''