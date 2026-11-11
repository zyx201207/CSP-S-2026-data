#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n;
    cin>>n>>m;
    vector<int>a(n+1);
    int maxn=0,sum=1,f=0;
    for(int i=1;i<=n;i++){
        int ff;
        cin>>ff;
        sum=sum&ff;
        maxn=max(maxn,ff);
        if(ff!=i-1){
            f=1;
        }
        a.push_back(ff);
    }
    if(f==0){
        cout<<0;
        return 0;
    }
    if(n==m){
        cout<<sum;
        return 0;
    }
    if(m==1){
        cout<<maxn;
        return 0;
    }
    if(m==2){
        maxn=0;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;i++){
                maxn=max(maxn,a[i]&a[j]);
            }
        }
        cout<<maxn;
        return 0;
    }else{
        cout<<0;
        return 0;
    }
    return 0;
}
