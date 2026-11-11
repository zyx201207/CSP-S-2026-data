#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int a[500005];
int diff[500005];
int ans[500005];
bool flag[500005];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(diff,0,sizeof(diff));
        memset(flag,0,sizeof(flag));
        for(int j=i;j<=n;j++){
            for(int k=i;k<j;k++){
                if(a[k]==a[j]&&!flag[k]){
                    for(int h=k;h<j;h++){
                        flag[h]=true;
                    }
                    break;
                }
            }
        }
        for(int j=i;j<=n;j++){
            if(!flag[j]){
                ans[a[j]]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout << ans[i] << ' ';
    }
    return 0;
}
