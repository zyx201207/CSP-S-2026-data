#include<bits/stdc++.h>
using namespace std;
long long n,a[500009],b[500009];
long long m;
int ans=-1;
void check(int k){
    int cnt=0;
        long long maxn=-1;
        for(int i=1;i<k;i++)maxn=max(maxn,a[i]);
        long long sum=0;
        for(int i=1;i<k;i++){
            sum=sum+k-b[i];
            cnt++;
        }
        if(sum<=m){
            ans=k;
        }

}
void dfs(int k,int floor,int j){
    if(k==floor){
        check(k);
        return;
    }
    for(int i=j;i<=n;i++){
        if(a[i]<=k){
            b[floor]=a[i];
            dfs(k,floor+1,i+1);
            b[floor]=0;
        }
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    bool f1=true;
    int cha=a[2]-a[1];
    for(int i=3;i<=n;i++){
        if(a[i]-a[i-1]!=cha){
            f1=false;
        }
    }
    if(f1){
        int cnt=0,sum=0,i=0;
        while(cnt<=n&&sum<=m){
                sum+=(cnt+cha);
                cnt+=cha;
                i++;
        }
        cout<<i;
        return 0;
    }
    for(int i=1;i<=n;i++){
        dfs(i,1,1);
    }
    cout<<ans;
    return 0;
}

