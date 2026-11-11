#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m,a[200010],ans,vis[200010],num,flag=1,temp;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            ans=max(ans,a[i]&a[j]);
        }
    }
    cout << ans;




    return 0;
}
