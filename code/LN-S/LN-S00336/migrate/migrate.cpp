#include <bits/stdc++.h>
using namespace std;
long long n,m,d,l;
vector<long long> aa;
vector<vector<long long>,long long> bb;
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
scanf("%lld%lld",&d,&l);
while(l--){
scanf("%lld%lld",&n,&m);
long long sum=0;
for(int i=1;i<=n;i++){
for(int j=1;j<=n;j++){
aa[i][j]=0;
}
}
for(int i=1;i<=n;i++){
scanf("%lld",aa[i]);
for(int j=1;j<i;j++){
if(aa[j]>=(aa[i]-m)){
bb[i][j]++;
}
for(int k=1;k<=j;k++){
if(aa[j]>=(aa[i]-m)){
bb[i][k]+=bb[j][k];
}
}
}
for(int j=1;j<i;j++){
if(bb[i][j]==2&&(aa[i]-aa[j])>m){
sum++;
}
}
}
printf("%lld",sum);
}
return 0;
}
