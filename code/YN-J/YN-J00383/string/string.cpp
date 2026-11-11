#include <bits/stdc++.h>;
using namespace std;
typedef long long LL;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
LL n,sum=0;
string zhen,dao;
cin>>n;
for(LL i=0;i<n;i++){
 LL m;
 char k;
    cin>>m>>k;
    for(LL j=0;j<m;j++){
            zhen.push_back(k);
}
}

 for(LL j=zhen.size();j>=0;j--){
    dao.push_back(zhen[j]);
}
for(LL j=zhen.size();j>=0;j--){
    if(zhen[j]!=dao[j]){
    sum++;
    }
    }
    cout<<sum;

return 0;
}
