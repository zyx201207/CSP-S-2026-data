#include<bits/stdc++.h>
using namespace std;
int n,m,a[500050];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;scanf("%d",&a[0]);
    for(int i=1;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]-a[i-1]) printf("%d ",i);
    }
    return 0;
}
