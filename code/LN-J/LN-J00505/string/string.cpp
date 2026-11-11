#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string s;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int m;
        char c;
        cin>>m>>c;
        while(m--)s+=c;
    }
    int ans=0;
    int k=s.size();
    for(int l=0,r=k-1;l<r;l++,r--)
    {
        if(s[l]!=s[r])ans++;
    }
    cout<<ans;
    return 0;
}
