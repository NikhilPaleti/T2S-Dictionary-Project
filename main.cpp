#include<bits/stdc++.h>
#include <windows.h>
using namespace std;

int main()
{
    char a[100];
    cout << "Welcome\n";
    system("welcome.vbs");

    cout << "\nEnter Word: ";
    gets(a);
    // puts(a);

    ofstream batch;
    batch.open("working.vbs", ios::out);
    batch << "'\n";
    batch << "set speech = Wscript.CreateObject(\"SAPI.spVoice\") \n";
    batch << "speech.speak\"" << a << "\" ";
    batch.close();

    system("working.vbs");
}
