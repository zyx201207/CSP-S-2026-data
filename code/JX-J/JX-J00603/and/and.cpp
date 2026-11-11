#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    int maxn=0;
    for(int i=1;i<=n-m+1;i++){
        int cnt=a[i];
        for(int j=i+1;j<=i+m-1;j++){
            cnt&=a[j];
        }
        maxn=max(cnt,maxn);
    }
    cout<<maxn;
    return 0;
}
