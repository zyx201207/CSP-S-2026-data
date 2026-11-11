#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[200001];
char b[200001];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    int ans=0;
    for(int i=1,j=n;i<j;)
    {
        if(b[i]!=b[j]) ans+=min(a[i],a[j]);
        if(a[i]>a[j])
        {
            a[i]-=a[j];
            j--;
        }
        else
        {
            a[j]-=a[i];
            i++;
        }
    }
    cout<<ans;
    return 0;
}
