#include<bits/stdc++.h>
using namespace std;

int c1,c2;
string s1,s2;
bool f1,f2,f3,f4;

int main()
{
    
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin >> c1 >> s1 >> c2 >> s2;
    if(c1==c2) f1 = 1;
    if(s1.substr(0,2)==s2.substr(0,2) && f1) f2 = 1;
    int pos1 = s1[2]-'A'+1,pos2 = s2[2]-'A'+1;
    if(pos1 == 6) pos1 = 5;
    if(pos2 == 6) pos2 = 5;
    if(f1 && f2 && ((pos1 <= 3 && pos2 <= 3) || (pos1 > 3 && pos2 > 3))) f3 = 1;
    if(f1 && f2 && f3 && abs(pos1-pos2)==1) f4 = 1;
    cout << f1 << f2 << f3 << f4;

    return 0;
}