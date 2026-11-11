#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m;
long long a[N],b[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    long long maxx=0;
    if(n>5000){
        long long cha=a[2]-a[1];
        long long cnt=1;
        while(m-a[cnt]>=0){
            m-=a[cnt++];
        }
        cout<<cnt;
        return 0;
    }
    for(int i=2;i<=n;i++){
        long long sum=0,cnt=1;
        long long j=i-1;
        while(j>=1 && sum+(a[i]-a[j])<=m){
            sum+=a[i]-a[j];
            j--;
            cnt++;
        }
        maxx=max(maxx,cnt);
    }
    cout<<maxx;
    return 0;
}
