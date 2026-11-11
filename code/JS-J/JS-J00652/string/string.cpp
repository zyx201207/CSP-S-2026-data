#include<bits/stdc++.h>
using namespace std;
int s[200010];
int a,p=1,ans,n;
char k;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        cin>>k;
        for(int i=1;i<=a;i++,p++)
            s[p]=k-'a';
    }
    --p;
    for(int i=1;p>i;i++,p--)
        if(s[i]!=s[p])
            ans++;
    cout<<ans;
    return 0;
}
