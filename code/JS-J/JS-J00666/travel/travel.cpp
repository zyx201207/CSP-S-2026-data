#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    cout<<(c1==c2);
    string row1="";
    for(int i=0;i<=1;i++)
    {
        row1+=s1[i];
    }
    string row2="";
    for(int i=0;i<=1;i++)
    {
        row2+=s2[i];
    }
    cout<<((c1==c2)&&(row1==row2));
    bool samerow=(row1==row2);
    bool samecar=(c1==c2);
    bool samesid=(((s1[2]-'A'+1)<=3 && (s2[2]-'A'+1)<=3) || ((s1[2]-'A'+1)>3 && (s2[2]-'A'+1)>3));
    bool isbesid=(abs(s1[2]-s2[2])==1);
    if((s1[2]=='D' && s2[2]=='F') || (s1[2]=='F' && s2[2]=='D'))
    {
        isbesid=true;
    }
    cout<<(samerow && samecar && samesid);
    cout<<(samerow && samecar && samesid && isbesid);
    return 0;
}
