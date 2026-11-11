#include<bits/stdc++.h>
using namespace std;
bool pd(char a,char b)
{
    int x=-1,y=-1;
    if(a=='A'||a=='B'||a=='C')
    {
        x=1;
    }
    else{
        x=0;
    }
    if(b=='A'||b=='B'||b=='C')
    {
        y=1;
    }
    else{
        y=0;
    }
    if(x==y)
    {
        return true;
    }
    else{
        return false;
    }
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >>s1 >>c2 >> s2;
    if(c1==c2)
    {
        cout <<"1";
    }
    else{
        cout << "0";
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2)
    {
        cout << "1";
    }
    else{
        cout << "0";
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&pd(s1[2],s2[2])==true&&c1==c2)
    {
        cout << "1";
    }
    else{
        cout << "0";
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&abs(s1[2]-s2[2])==1&&pd(s1[2],s2[2])==true&&c1==c2)
    {
        cout << "1";
    }
    else{
        cout << "0";
    }
	return 0;
}
