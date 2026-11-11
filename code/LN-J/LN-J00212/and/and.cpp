#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n,m;
int ans[200005];
int st[200005];
int mx;
void DFS(int step){
    if(step==m+1){
        int sum=ans[1];
        for(int i=2;i<step;i++){
            sum=sum&ans[i];
        }
        mx=max(mx,sum);
        return;
    }
    for(int i=1;i<=n;i++){
        if(st[i]==0){
            st[i]=1;
            ans[step]=a[i];
            DFS(step+1);
            st[i]=0;
        }
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int f=1;
    int l=1;
    for(int i=1;i<=n;i++){
        int x=a[i];
        if(log2(x+1)!=int(log2(x+1))){
            f=0;
            break;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]!=i-1){
            l=0;
            break;
        }
    }
    if(f){
        sort(a+1,a+1+n,greater<int>());
        long long sum=a[1];
        for(int i=2;i<=m;i++){
            sum=sum&a[i];
        }
        cout<<sum;
    }else if(l && log2(n)==int(log2(n))){
        sort(a+1,a+1+n,greater<int>());
        long long sum=a[1];
        for(int i=2;i<=m;i++){
            sum=sum&a[i];
        }
        cout<<sum;
    }else if(m==1){
        int mx=-2e9;
        for(int i=1;i<=n;i++){
            mx=max(mx,a[i]);
        }
        cout<<mx;
    }else if(m==n){
        long long sum=a[1];
        for(int i=2;i<=n;i++){
            sum=sum&a[i];
        }
        cout<<sum;
    }else{
        DFS(1);
        cout<<mx;
    }
    return 0;
}
