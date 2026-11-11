#include <iostream>
#include <cmath>
using namespace std;
long long n,m;
int a[200005],b[200005],cnt[2000005];
void q(int js){
    for(int i=0;i<=200004;i++) b[i]=0;
}
bool zai(int za){
    for(int i=1;i<=200004;i++) if(za==b[i]) return 0;
    return 1;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >>  n >> m;
    for(int i=1;i<=n;i++)cin >> a[i];
    for(int i=1;i<=n;i++){//n
        for(int j=i;j<=n;j++){
            if(zai(a[j])) q(1);
            for(int chi=1;chi<=j;chi++) if(b[chi]==0) b[chi] = a[j];
        }
        for(int j=1;j<=m;j++) cnt[b[j]]++;
    }
    for(int i=1;i<=m;i++) cout << cnt[i] << " "; 
}
