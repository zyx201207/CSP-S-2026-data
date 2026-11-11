#include<bits/stdc++.h>
using namespace std;
long long a[200001],n,m,maxn=-1,maxa=-1,f;
map<int,int> mp;
void DFS(int k,long long sum){
    if(k==m){
        maxn=max(maxn,sum);
        return;
    }
    for(int i=1;i<=n;i++){
        if(mp[i]==0){
            mp[i]=1;
            DFS(k+1,sum&a[i]);
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxa=max(maxa,a[i]);
        if(a[i]%2==0) f=1;
    }
    sort(a+1,a+n+1,greater<long long>());
    if(n<=20){
        DFS(0,1048575);
        cout<<maxn;
    }
    else if(m==1) cout<<a[1];
    else if(m==n){
        long long ans=1048575;
        for(int i=1;i<=n;i++) ans&=a[i];
        cout<<ans;
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            if(a[i]<maxn) break;
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                if(a[j]<maxn) break;
                maxn=max(maxn,a[i]&a[j]);
            }
        }
        cout<<maxn;
    }
    else if(maxa<4){
        int h[4];
        for(int i=1;i<=n;i++) h[a[i]]++;
        if(h[3]>=m) cout<<3;
        else if(h[2]>=m) cout<<2;
        else if(h[1]+h[3]>=m) cout<<1;
        else cout<<0;
    }
    else if(f==1){
        long long cnt=a[1];
        for(int i=1;i<=m;i++) cnt&=a[i];
        cout<<cnt;
    }
    else cout<<0;
    return 0;
}
