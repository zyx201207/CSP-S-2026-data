#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long ans=0;
long long n,m,a[N];
void dfs(int st ,int k,long long t){
    if(k==m){
        ans=max(ans,t);
    }
    for(int i=st;i<=n;i++){
        dfs(i+1,k+1,t&a[i]);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=20){
        long long t=(1<<22)-1;
        dfs(1,0,t);
    }else if(n<=2000){
        sort(a+1,a+n+1);
        if(m==1){
            ans=a[1];
        }else if(m==2){
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    ans=max(ans,a[i]&a[j]);
                }
            }
        }else{
            ans=a[1];
            for(int i=1;i<=n;i++){
                ans&=a[i];
            }
        }
    }else{
        bool s=1,t=1;
        long long f=0,g=0,j=0;
        for(int i=1;i<=n;i++){
            if(a[i]>=4){
                s=0;
            }
            f+=(a[i]==3);
            g+=(a[i]==2);
            j+=(a[i]==1);
            if(((a[i]+1)&a[i])!=0){
                t=0;
            }
        }
        if(s){
            if(f>=m){
                ans=3;
            }else if(f+g>=m){
                ans=2;
            }else if(f+j>=m){
                ans=1;
            }else{
                ans=0;
            }
        }else if(t){
            sort(a+1,a+n+1);
            ans=a[m];
        }else{
            ans=0;
        }
    }
    cout<<ans;
    return 0;
}
