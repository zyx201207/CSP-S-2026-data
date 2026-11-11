#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
long long n,a[1000000005];
char c;
cin>>n>>endl;
for(int i=0;i<n;i++){
    cin>>a[i]>>c>>endl;
}
int o=0;
for(int i=0;i<n;i++){
    if(a[i]!=a[n-i]){
        o++;
    }else{
        continue;
    }
}
cout<<o;
return 0;
}
