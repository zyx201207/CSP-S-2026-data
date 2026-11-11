#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
char ch[200005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i]>>ch[i];
    }
    int l=1,r=n;
    int ans=0;
    while (l<r){
        if (a[l]==0)l++;
        if (a[r]==0)r--;
        if (l==r||l>r)break;
        int k=min(a[l],a[r]);
        if (ch[l]!=ch[r])ans+=k;
        a[l]-=k;
        a[r]-=k;
    }
    cout<<ans<<endl;
    return 0;
}