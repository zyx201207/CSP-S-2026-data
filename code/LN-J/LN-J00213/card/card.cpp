#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 300005
int sum[N],n,m,a[N],cnt[N];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int t=0;t<n;t++){
        for(int i=0;i<=m;i++)cnt[i]=0;
        stack<int> r;
        for(int i=t;i<n;i++){
            if(cnt[a[i]]==0)cnt[a[i]]++,r.push(a[i]);
            else{
                while(r.top()!=a[i]){
                    cnt[r.top()]--;
                    r.pop();
                }
            }
        }
        for(int i=0;i<=m;i++)sum[i]+=cnt[i];
    }
    for(int i=1;i<=m;i++){
        cout<<sum[i]<<' ';
    }
}
