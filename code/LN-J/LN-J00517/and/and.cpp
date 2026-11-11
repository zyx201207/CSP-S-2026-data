#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m,ma=-1;
int sum[N];
int lo(int a){
    int mi2=0;
    for(int i=1;i<=20;i++){
        if(a>>i&1) mi2=i;
    }
    return mi2+1;
}
bool cmp(int a,int b){
    if(lo(a)==lo(b)) return a>b;
    return lo(a)>lo(b);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>sum[i];
        ma=max(ma,sum[i]);
    }
    if(m==1){
        cout<<ma;
        return 0;
    }
    if(m==n){
        int ans=sum[1];
        for(int i=2;i<=n;i++){
            ans=sum[i]&ans;
        }
        cout<<ans;
        return 0;
    }
    if(m==2){
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,sum[j]&sum[i]);
            }
        }
        cout<<ans;
        return 0;
    }
    /*if(m==n-1){
        int cnt=-1;
        for(int i=1;i<=n;i++){
			int ans=sum[i];
            for(int j=1;j<=n;j++){
                if(j==i) continue;
                ans=ans&sum[j];
            }
            cnt=max(ans,cnt);
        }
        cout<<cnt;
        return 0;
    }*/
    sort(sum+1,sum+n+1,cmp);
    int ans=sum[1],cnt=0;
    for(int i=2;i<=n;i++){
        if(sum[i]==sum[i]-1) continue;
        else{
            cnt++;
            ans=ans&sum[i];
            if(cnt==m-1) break;
        }
    }
    cout<<ans;
    return 0;
}

