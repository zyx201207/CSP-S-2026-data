#include<bits/stdc++.h>
using namespace std;
long long n,cnt1,cnt2=0,a[200005];
string s,c;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(flase);
    cin.tie(nullptr);
    bool flag=1;
    cin>>n>>a[0]>>c[0];
    cnt1=a[0];
    for(int i=1;i<n;i++)
    {
        cin>>a[i]>>c[i];
        cnt1+=a[i];
        if(c[i]!=c[i-1]) flag=0;
    }
    if(flag==1)
    {
        cout<<0;
        return 0;
    }
    for(int i=0;i<n;i++) for(int j=0;j<a[i];j++) s+=c[i];
    for(int j=0;j<(cnt1+1)/2;j++)
    {
        if(s[j]!=s[cnt1-j-1])
        {
            cnt2++;
            cout<<s[j]<<s[cnt1-j-1]<<'\n';
        }
    }
    cout<<cnt2;
    return 0;
}
