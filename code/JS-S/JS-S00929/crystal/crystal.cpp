#include<bits/stdc++.h>
using namespace std;
long long n,m,x,ans = 0,p,q = 1;
long long al[500005],qz[500005];
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
scanf("%d%d",&n,&m);

for(int i = 1;i <= n;i++){
        scanf("%lld",&al[i]);
        if(i == 2){
            p = al[i]-al[i-1];
        }
        if(i > 2){
            if(al[i]-al[i-1]!=p)q = 0;
        }
}
sort(al+1,al+n+1);
if(q){
    int t = m/p;
    int x = 1;
    while(t > 0){
        t -= x;
        x+1;
    }
    cout<<x-1;
    return 0;
}
for(int i = 1;i <= n;i++){
    qz[i] = qz[i-1] + (al[i]-al[i-1])*(i-1);
}
for(long long i = 1;i < n;i++){
    for(long long j = i+1;j<= n;j++){
        if(qz[j]-qz[i] <= m){
            ans = max(ans,j-i+1);
        }
    }
}
cout<<ans;
return 0;
}
