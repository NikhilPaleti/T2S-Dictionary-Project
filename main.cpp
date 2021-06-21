#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

struct Tree
{
    bool isEndOfWord;
    unordered_map<char, Tree *> map;
    string meaning;
};

Tree *getNewTreeNode()
{
    Tree *node = new Tree;
    node->isEndOfWord = false;
    return node;
}

void insert(Tree *&root, const string &str, const string &meaning)
{

    if (root == NULL)
        root = getNewTreeNode();

    Tree *temp = root;
    for (int i = 0; i < str.length(); i++)
    {
        char x = str[i];

        // Make a new node if there is no path
        if (temp->map.find(x) == temp->map.end())
            temp->map[x] = getNewTreeNode();

        temp = temp->map[x];
    }

    temp->isEndOfWord = true;
    temp->meaning = meaning;
}

string getMeaning(Tree *root, const string &word)
{

    if (root == NULL)
        return "";

    Tree *temp = root;

    for (int i = 0; i < word.length(); i++)
    {
        temp = temp->map[word[i]];
        if (temp == NULL)
            return "";
    }

    if (temp->isEndOfWord)
        return temp->meaning;
    return "";
}

int main()
{
    Tree *root = NULL;

    insert(root, "language", "the method of human communication");
    insert(root, "Laptop", "A computer is a machine that can be instructed to carry out sequences of arithmetic or logical operations automatically via computer programming");
    insert(root, "bedsheet", "a diagrammatic representation of an area");
    insert(root, "book", "a written or printed work consisting of pages glued or sewn together along one side and bound in covers.");
    insert(root, "science", "the intellectual and practical activity encompassing the systematic study of the structure and behaviour of the physical and natural world through observation and experiment.");

 
    cout << "Welcome\n";
    system("welcome.vbs");

    char Word[20];
    cout << "\nEnter Word: ";
    gets(Word);
    string meaningTalk = getMeaning(root, Word);
    cout << getMeaning(root, Word);
    // puts(a);

    // Creation and execution of Speech API
    ofstream batch;
    batch.open("working.vbs", ios::out);
    batch << "'\n";
    batch << "set speech = Wscript.CreateObject(\"SAPI.spVoice\") \n";
    batch << "Set speech.Voice = speech.GetVoices.Item(1)\n";
    batch << "speech.speak\"" << meaningTalk << "\" ";
    batch.close();

    system("working.vbs");
}