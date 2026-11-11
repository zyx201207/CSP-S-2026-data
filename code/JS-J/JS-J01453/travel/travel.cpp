#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool check1(char a,char b)
{
    bool flag1=0,flag2=0;
    if(a=='A'||a=='B'||a=='C') flag1=1;
    if(b=='A'||b=='B'||b=='C') flag2=1;
    return flag1==flag2;
}
bool check2(char a,char b)
{
    int A,B;
    if(a=='F') A=5;
    else A=a-64;
    if(b=='F') B=5;
    else B=b-64;
    if(A==3&&B==4||A==4&&B==3) return 0;
    return abs(A-B)==1;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1!=c2)
    {
        cout << "0000";
        return 0;
    }
    if(s1[0]!=s2[0]||s1[1]!=s2[1])
    {
        cout << "1000";
        return 0;
    }
    if(!check1(s1[2],s2[2]))
    {
        cout << "1100";
        return 0;
    }
    if(!check2(s1[2],s2[2]))
    {
        cout << "1110";
        return 0;
    }
    cout << "1111";
    return 0;
}
