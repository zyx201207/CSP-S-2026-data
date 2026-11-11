#include<bits/stdc++.h>
using namespace std;
string c1,c2;
string s1,s2;
int cnt[5],ans[5],sum;
int n=0,m=0;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<"1";
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    for(char c:s1)
    {
        n++;
        if(c>='0'&&c<='8')
            cnt[n]=c;
    }
    for(char c:s2)
    {
        m++;
        if(c>='0'&&c<='8')
            ans[m]=c;
    }
    for(int i=1; i<=2; i++)
    {
        if(cnt[i]==ans[i])
        {
            sum++;
        }
        else
        {
            cout<<"000";
            return 0;
        }
    }
    if(sum==2) cout<<"1";
    for(char c:s1)
    {
        if(c>='A'&&c<='F')
            cnt[3]=c;
    }
    for(char c:s2)
    {
        if(c>='A'&&c<='F')
            ans[3]=c;
    }
    if(cnt[3]=='A'&&ans[3]=='B'||ans[3]=='C') cout<<1;
    else if(cnt[3]=='A'&&ans[3]=='C'||ans[3]=='B') cout<<1;
    else if(cnt[3]=='B'&&ans[3]=='A'||ans[3]=='C') cout<<1;
    else if(cnt[3]=='B'&&ans[3]=='C'||ans[3]=='A') cout<<1;
    else if(cnt[3]=='C'&&ans[3]=='B'||ans[3]=='A') cout<<1;
    else if(cnt[3]=='C'&&ans[3]=='A'||ans[3]=='B') cout<<1;
    else if(cnt[3]=='E'&&ans[3]=='F'){
        cout<<"11";return 0;
    }
    else if(cnt[3]=='F'&&ans[3]=='E'){
        cout<<"11";return 0;
    }
    else{
        cout<<"00";
        return 0;
    }
    if(cnt[3]=='A'&&ans[3]=='B') cout<<1;
    else if(cnt[3]=='B'&&ans[3]=='A') cout<<1;
    else if(cnt[3]=='B'&&ans[3]=='C') cout<<1;
    else if(cnt[3]=='C'&&ans[3]=='B') cout<<1;
    else{
        cout<<"0";
    }
    return 0;
}
