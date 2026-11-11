#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200010];
char c[200010];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int x=1,y=n;
    int tot=0;
    while (x<=y){
        if (c[x]==c[y]){
            if (a[x]==a[y]){
                a[x]=a[y]=0;
                x++,y--;
            }
            else if (a[x]>a[y]){
                a[x]-=a[y];
                a[y]=0;
                y--;
            }
            else{
                a[y]-=a[x];
                a[x]=0;
                x++;
            }
        }
        else{
            if (a[x]>a[y]){
                tot+=a[y];
                a[x]-=a[y];
                a[y]=0;
                y--;
            }
            else if (a[y]>a[x]){
                tot+=a[x];
                a[y]-=a[x];
                a[x]=0;
                x++;
            }
            else{
                tot+=a[x];
                a[x]=a[y]=0;
                x++,y--;
            }
        }
    }
    cout<<tot;
    return 0;
}