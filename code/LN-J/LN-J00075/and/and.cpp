#include<bits/stdc++.h>
using namespace std;

int n,m;
long long a[200010];
long long ans;
int b[30];
void bfs(int x,long long num,int c){
    if(c==m){
        ans=max(ans,num);
        return;
    }
    for(int i=x+1;i<=n;i++){
        bfs(i,num&a[i],c++);
    }
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    if(m==1){
        for(int i=1;i<=n;i++){
        cin>>a[i];
        ans=max(ans,a[i]);
        }
    }else if(m==2){
        for(int i=1;i<=n;i++){
            cin>>a[i];
            for(int j=i-1;j>0;j--){
                long long x=a[i]&a[j];
                ans=max(ans,x);
            }
        }
    }else if(m==n){
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i==1)ans=a[i];
            else ans=ans&a[i];
        }
    }else{
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        long long xx=2*2*2*2*2*2*2*2*8*2*2*2*2*2*2*2*2*2-1;
        bfs(0,xx,0);
    }
    cout<<ans;
    return 0;
}

