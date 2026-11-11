#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","s",stdout);
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    int maxn=1;
    for(int i=1;i<=m;i++){
        int cnt=1;
        for(int j=1;j<=n;j++){
            if(a[j]<a[j+1]){
                a[j]++;
                break;
            }
        }
        for(int j=2;j<=n;j++){
            if(a[j]==a[j-1]){
                cnt++;
            }
            else{
                maxn=max(maxn,cnt);
                cnt=1;
            }
        }
        maxn=max(maxn,cnt);
    }
    cout<<maxn;
    return 0;
}
