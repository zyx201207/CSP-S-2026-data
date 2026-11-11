#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5,M=3e5+5;
ll n,a[N],m,b[N],tb[N];
ll tbl[M];
bool flp=1;
void pianA(){
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            tbl[j]++;
        }
    }for(int i=1;i<=m;i++)
    cout<<tbl[i]<<' ';
        }

void ano(){
    int pos=n;
for(int i=1;i<=n;i++){
    for(int j=i;j<=n;j++){

    }
}
}
int main(){
    //card
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
    b[i]=a[i];
}
sort(b+1,b+n+1);
for(int i=1;i<=n;i++){
    if(a[i]!=b[i])flp=0;
}if(flp){
    pianA();
    return 0;
}
ano();
      return 0;
}//hope to offer problems as easy as cout"Hello World"
