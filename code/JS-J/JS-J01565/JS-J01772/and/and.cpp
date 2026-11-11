#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n,m,num,ans;
int a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        num = (num&a[i]);
    }
    sort(a+1,a+1+n);
    if(m==1){
        cout<<a[1];
        return 0;
    }
    if(n==m){
        cout<<num;
    }
    if(m==2){
        for(int i = 1;i<n;i++){
            for(int j = i;j<=n;j++){
                ans = max(ans,(a[i]&a[j]));
            }
        }
        cout<<ans;
    }
    if(m==n-1){
        for(int i = 1;i<=n;i++){
            ans = max(ans,(num&a[i]));
        }
        cout<<ans;
    }
    return 0;
}