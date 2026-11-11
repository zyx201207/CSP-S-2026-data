#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200006];
long long pa[36];
/*
int vis[36];
vector<long long> v[36];
vector<int> l;
int av[200006];
*/
long long ans=0;
void dfs(long long x,long long c,long long sum){
    if(c==m){
        ans=max(ans,sum);
        return;
    }
    for(long long i=x+1;i<=n;i++){
        dfs(i,c+1,sum&a[i]);
    }
}
void csh(){
    for(long long i=0;i<=31;i++){
        pa[i]=round(pow(2,i)-1);
    }
}
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    /*for(int i=1;i<=n;i++){
        cin>>a[i];
        long long w=30;
        long long pw=round(pow(2,30));
        long long lin=a[i];
        while(lin!=0){
            if(lin>=pw){
                v[w].push_back(i);
                lin-=pw;
                vis[w]++;
            }
            pw/=2;
            w--;
        }
    }
    */
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=20){
        dfs(0,0,round(pow(2,31)-1));
        cout<<ans;
        return 0;
    }
    if(m==n){
        ans=round(pow(2,31)-1);
        for(int i=1;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }
    csh();
    bool z=1;
    for(int i=1;i<=n;i++){
        bool lz=0;
        for(int j=0;j<=31;j++){
            if(pa[j]==a[i]){
                lz=1;
                break;
            }
        }
        if(lz==0){
            z=0;
            break;
        }
    }
    if(z==1){
        sort(a+1,a+n+1,cmp);
        ans=round(pow(2,31)-1);
        for(int i=1;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans;
    }

    return 0;
}
