#include<bits/stdc++.h>
using namespace std;
int n,m,ans,cnt,num;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    ans = a[n];
    if(m==1){
        cout<<ans;
    }
    else if(m==n){
        for(int i=1;i<=n;i++){
            int cnt = a[1];
            cnt &= a[i];
        }
        cout<<cnt;
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                num = max(num,a[i]&a[j]);
            }
        }
        cout<<num;
    }
    return 0;
}
