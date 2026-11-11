#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200100;

inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-'){
            f=-1;
        }
        ch=getchar();
    }
    while(ch<='9'&&ch>='0'){
        x=x*10+(int)(ch-48);
        ch=getchar();
    }
    return x*f;
}
bool check(int k){
    while(k%2==0){
        k/=2;
    }
    if(k==1)return 1;
    else return 0;
}
int a[N]={};
int n,m;
int dfs(int dep,int cnt){
    if(dep>m){
        return cnt;
    }
    if(cnt==-1){
        int mx=0;
        for(int i=1;i<=n;i++){
            mx=max(mx,dfs(dep+1,a[i]));
        }
        return mx;
    }
    int mx=0;
    for(int i=1;i<=n;i++){
        mx=max(mx,dfs(dep+1,cnt&a[i]));
    }
    return mx;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    if(n<=20){
        dfs(1,-1);
    }
    sort(a+1,a+1+n,greater<>());
    if(n==1){
        cout<<a[1];
        return 0;
    }
    if(m==2){
        int mx=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(i==j){
                    continue;
                }
                mx=max(mx,(a[i]&a[j]));
            }
        }
        cout<<mx;
        return 0;
    }
    int ans;
    for(int i=1;i<=m;i++){
        if(i==1)ans=a[i];
        else ans&=a[i];
    }
    cout<<ans;
}
