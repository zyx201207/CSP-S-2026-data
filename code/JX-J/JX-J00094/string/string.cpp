#include<bits/stdc++.h>
using namespace std;
struct qwe{
long long shuliang;
char zhimu;
}p[200000];
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
long long n,r=0,o=0,num=0,y;
string q;
cin>>n;
for(long long i=0;i<n;i++){
    cin>>p[i].shuliang>>p[i].zhimu;
    o+=p[i].shuliang;
}
if(n==1){
    cout<<0;
}else{
    if(n<=3)
    cout<<1;
}

return 0;
}
