#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    bool is = true;
    for(int i = 0;i < 2;i++)
    {
        if(c1[i] != c2[i]) is = false;
    }
    if(is == true) cout << "1";
    else cout << "0";
    bool is1 = true;
    for(int i = 0;i < 2;i++)
    {
        if(s1[i] != s2[i]) is = false;
    }
    if(is1 == true&&is == true) cout << "1";
    else cout << "0";
    bool is2 = false;
    for(int i = 0;i < 1;i++)
    {
        if((s1[2] == 'A'||s1[2] == 'B'||s1[2] == 'C')&&(s2[2] == 'A'||s2[2] == 'B'||s2[2] == 'C'))
        {
            is2 = true;
        }
        else if((s1[2] == 'D'||s1[2] == 'F')&&(s2[2] == 'D'||s2[2] == 'F'))
        {
            is2 = true;
        }
    }
    if(is2 == true&&is1 == true&&is == true) cout << "1";
    else  cout << "0";
    bool is3 = false;
    for(int i = 0;i < 1;i++)
    {
        if(s1[2] == 'A'&&s2[2] == 'B') is3 = true;
        else if(s1[2] == 'B'&&s2[2] == 'A') is3 = true;
        else if(s1[2] == 'B'&&s2[2] == 'C') is3 = true;
        else if(s1[2] == 'C'&&s2[2] == 'B') is3 = true;
        else if(s1[2] == 'D'&&s2[2] == 'F') is3 = true;
        else if(s1[2] == 'F'&&s2[2] == 'D') is3 = true;
    }
    if(is3 == true&&is2 == true&&is1 == true&&is == true) cout << "1";
    else cout << "0";
    return 0;
}
