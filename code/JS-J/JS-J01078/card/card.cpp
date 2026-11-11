#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    int ans;
    if(n==m)for(int i=1;i<=n;i++)cout<<i<<" ";
    else {
        int num=0,c;
        for(int i=n;i>=1;i--)if(a[i]==a[i-1]){num=i,c=a[i];break;}
        for(int i=1;i<=n;i++){
            if(i<num)cout<<0<<" ";
            else cout<<i<<" ";
        }
    }
    return 0;
}
