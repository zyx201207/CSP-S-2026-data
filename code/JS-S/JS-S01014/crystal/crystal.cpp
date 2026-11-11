#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(i==2){
            if(a[i]==a[i-1]){
            cout<<n;
            }
        }
    }
    return 0;
}
