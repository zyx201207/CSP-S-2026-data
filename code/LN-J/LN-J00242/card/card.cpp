#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ll n,m,N=0;
    scanf("%d%d",&n,&m);
    int a[500005];
    int b[500005]={0};
    int tmp=-1;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(tmp!=a[i]){
            tmp=a[i];
            b[N++]=a[i];
        }
    }
    tmp=1;
    for(int i=1;i<=m;++i){
        if(i==b[tmp]){
            cout<<tmp;
            tmp++;
        }else
            cout<<'0';
    }
    return 0;
}
