#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
long long n,m,cr[500010]={},ch[500010]={},ch2[500010]={};
cin>>n>>m;
for(long long i=0;i<n;i++){
    cin>>cr[i];
}
for(long long i=0;i<n;i++){
    if(i){
        ch[i]=cr[i]-cr[i-1];
    }
}
long long sum=0,ii=0,ma=0,k=0;
for( long long i=n-1;i>0;i--){
        k=1;
        ii=i;
        sum=0;
        for(int j=1;j<n;j++){
            ch2[j]=ch[j];
        }
    while(sum<m&&ii>0){
        sum+=ch2[ii];
        ch2[ii-1]+=ch2[ii];
        ii--;
        k++;
    }
if(sum>m){
        k--;
}
    ma=max(k ,ma);

}
cout<<ma;
fclose(stdin);
fclose(stdout);
return 0;
}

