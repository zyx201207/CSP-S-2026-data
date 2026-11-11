#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int ans=-INT_MAX,len=0;
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(m>=(i-1)*(a[i]-a[i-1])) m-=len*(a[i]-a[i-1]),q.push(a[i]),len++,ans=max(len,ans);
        else{
            while(m<len*(a[i]-a[i-1])){
                m+=a[i-1]-q.front();
                q.pop();
                len--;
            }
            q.push(a[i]);
            m-=len*(a[i]-a[i-1]);
            len++;
            ans=max(ans,len);
        }
    }
    cout<<ans;
    return 0;
}
