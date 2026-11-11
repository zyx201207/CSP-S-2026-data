#include<bits/stdc++.h>
using namespace std;
int a[200005];
int cnt,lst;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    lst=n;
    for (int i=1;i<=n;i++)scanf("%d",&a[i]);
    for (int i=30;i>=0;i--){
        cnt=0;
        for (int j=1;j<=lst;j++){
            if ((a[j]&(1<<i))!=0)cnt++;
        }
        if (cnt>=m){
            cnt=0;
            for (int j=1;j<=lst;j++){
                if ((a[j]&(1<<i))!=0)a[++cnt]=a[j];
            }
            lst=cnt;
        }
    }
    int ans=(1<<30)-1;
    for (int i=1;i<=m;i++){
        ans&=a[i];
    }
    printf("%d\n",ans);
    return 0;
}