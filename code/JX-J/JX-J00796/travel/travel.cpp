#include<bits/stdc++.h>
using namespace std;
string a[3],b[3];
char s1[3],s2[3];
int main()
{
    freopen("travel.in","r","std.in");
    freopen("travel.out","w", "std.out");
    string c1,c2;
    cin >> c1 >> s1>> c2 >> s2;
    a[0]=s1[0],a[1]=s1[1],a[2]=s1[2];
    b[0]=s2[0],b[1]=s2[1],b[2]=s2[2];
    if(c1==c2 &&c1!="01" &&c1!="16")
    {
        cout << "1";
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            cout << "1";
            if(a[2]=="F"&&b[2]=="D" || a[2]=="D" && b[2]=="F")
            {
                cout << "1" << "1";
            }
            else if(a[2] != "F"&& a[2] != "D" && b[2]!="F" && b[2] !="D" && a[2]==b[2])
            {
                cout << "1";
                if(a[2]=="A" && b[2]=="B")
                {
                    cout << "1";
                }
                else if(a[2]=="B" && a[2] != b[2])
                {
                    if(b[2]=="A" || b[2]=="C")
                    {
                        cout << "1";
                    }
                }
                else if(a[2]=="C" && b[2]=="B")
                {
                    cout << "1";
                }
                else
                {
                    cout << "0";
                }
            }
            else
            {
                cout << "0" <<"0"<<"0";
            }
        }
        else
        {
            cout << "0" <<"0" << "0" << "0";
        }
    }
    return 0;
}
