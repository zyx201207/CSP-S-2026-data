#include<bits/stdc++.h>
using namespace std;
int n,a[300005],ma=0;
int y(int c,int z){
    int jie=0;

for(int i=c;i>0;i--){
        jie=max(jie,y(c-1,a[c]&a[i]));
}
return jie;
}
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n;
for(int i=0;i<n;i++){
    cin>>a[i];
}
sort(a,a+n);
for(int i=n;i>0;i--){
    ma=y(i,a[i]);
}
    cout<<ma;
return 0;
}

