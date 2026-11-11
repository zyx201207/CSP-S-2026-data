#include<bits/stdc++.h>
using namespace std;
#define int long long
bool flag=true;
string s1,c1,s2,c2;
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    clock_t st=clock();
    cin>>s1>>c1>>s2>>c2;
    if(s1[0]==s2[0] && s1[1]==s2[1]) printf("1");
    else  {printf("0000");return 0;}
    if(c1[0]==c2[0] && c1[1]==c2[1]) printf("1");
    else {printf("000");return 0;}
    if(c1[2]-'A'<=2 && c2[2]-'A'<=2) printf("1");
    else if(c1[2]-'A'>=3 && c2[2]-'A'>=3) {printf("11");return 0;}
    else {printf("00"); return 0;}
    if(abs((c1[2]-'A')-(c2[2]-'A'))==1)printf("1");
    else printf("0");
    return 0;
}
