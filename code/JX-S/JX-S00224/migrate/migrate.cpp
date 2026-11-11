#include<bits/stdc++.h>
using namespace std;
const int N=2e6+15;
int a[N],n,d;
bool qwq(int x,int y){
    if(a[y]-a[x]<=d) return 0;
    if(a[y-1]-a[x]<=d&&a[y]-a[x+1]<=d) return 1;
    return 0;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,x,cou[N];
    cin>>c>>t;
    x=t;
    while(x--){
        int cnt=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<n-2;i++){
            for(int j=i+1;j<=n;j++){
                if(qwq(i,j)) cnt++;
            }
        }cou[t-x]=cnt;
    }for(int i=1;i<=t;i++) cout<<cou[i]<<endl;
    return 0;
}
