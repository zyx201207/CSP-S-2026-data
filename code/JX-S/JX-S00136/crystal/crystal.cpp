#include<bits/stdc++.h>
using namespace std;
int n,m,l;
long long a[500005];
long long c[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int maxn=-1;
    int len=0;
    for(int i=1;i<=n;i++){
        len=0;
        long long sum=0;
        for(int j=i;j<=n;j++){
            if(sum+a[j]-a[i]<=m)
                len++;
            else
                break;
        }
        maxn=max(maxn,len);
    }
    cout<<maxn;
    return 0;
}
