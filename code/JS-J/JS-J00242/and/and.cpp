#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
unsigned long long n,m;
unsigned long long ans;
unsigned long long a[N];
bool v[N];
bool tA=true;
unsigned long long p2[61];
bool A(unsigned long long x){
    if(x==0){
        return false;
    }
    unsigned long long res=x+1;
    for(int i=1;i<=60;i++){
        if(p2[i]==res){
            return true;
        }
        if(p2[i]>res){
            return false;
        }
    }
    return false;
}
unsigned long long dfs(unsigned long long sum,unsigned long long st){
    if(st==m){
        return sum;
    }
    if(sum<ans){
        return st;
    }
    unsigned long long res=0;
    for(unsigned long long i=0;i<n;i++){
        if(!v[i]){
            v[i]=true;
            res=max(res,dfs(sum&a[i],st+1));
            ans=max(ans,res);
            v[i]=false;
        }
    }
    return res;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    p2[0]=1;
    for(int i=1;i<=60;i++){
        p2[i]=p2[i-1]*2;
    }
    unsigned long long mx=0;
    for(unsigned long long i=0;i<n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
        if(!A(a[i])){
            tA=false;
        }
    }
    if(m==1){
        cout<<mx;
        return 0;
    }
    if(m==n){
        ans=a[0];
        for(unsigned long long i=1;i<n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    if(tA){
        sort(a,a+n);
        cout<<a[n-m];
        return 0;
    }
    else{
        for(unsigned long long i=0;i<n;i++){
            if(!v[i]){
                v[i]=true;
                ans=max(ans,dfs(a[i],1));
                v[i]=false;
            }
        }
        cout<<ans;
        return 0;
    }
}
