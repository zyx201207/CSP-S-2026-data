#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[100005],b[100005];
int er(int x){
    int id = 1,ans = 0;
    while(x!=0){
        ans+=id*(x%2);
        id*=10;
        x/=2;
    }
    return ans;
}
int re(int x){
    int ans = 0,id = 1;
    while(x!=0){
        ans+=(x%10)*id;
        id*=2;
        x/=10;
    }
    return ans;
}
int annd(int x,int y){
    return x&y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int i = 1;i<=n;i++){
        b[i] = er(a[i]);
    }
    sort(a+1,a+1+n);
    if(m==1){
        cout<<a[n];
        return 0;
    }
    int ans = -1;
    if(m==2){
        for(int i = 1;i<n;i++){
            for(int j = i+1;j<=n;j++){
                if(j==i){
                    continue;
                }
                ans = max(ans,annd(b[i],b[j]));
            }
        }
        cout<<re(ans);
        return 0;
    }
    if(m==n){
        ans = b[1];
        for(int i = 2;i<=n;i++){
            ans = annd(ans,b[i]);
        }
        cout<<re(ans);
        return 0;
    }
    if(n>=2000){
        cout<<a[1];
        return 0;
    }
    return 0;
}
