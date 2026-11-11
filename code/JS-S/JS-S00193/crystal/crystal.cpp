#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long a[N],b[N];
long long n,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long maxd=-1;
    for(int i=2;i<=n;i++){
        long long cnt=0,m1=m;
        for(int j=1;j<=n;j++){
            b[j]=a[j]-a[i];
        }
        for(int j=1;j<=n&&m1>=0;j++){
            if(b[j]>0){
                m1=-1;
                continue;
            }
            m1+=b[j];
            if(m1>=0){
                cnt++;
            }
        }
        maxd=max(maxd,cnt);
    }
    cout<<maxd;
    return 0;
}
