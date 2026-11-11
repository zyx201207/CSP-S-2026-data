#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
void check()
{
    char x1=s1[s1.size()-1],x2=s2[s2.size()-1];
    string s="";
    s+=char(min(x1,x2));
    s+=char(max(x1,x2));
    if(s=="AB"||s=="BC"||s=="DF") cout<<"1111";
    else if(s=="AC") cout<<"1110";
    else cout<<"1100";
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2) cout<<"0000";
    else
    {
        string r1=s1,r2=s2;
        r1.erase(r1.end()-1);
        r2.erase(r2.end()-1);
        if(r1!=r2) cout<<"1000";
        else
            check();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
