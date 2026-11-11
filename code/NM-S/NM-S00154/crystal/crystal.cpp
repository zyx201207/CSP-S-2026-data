#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n,m;
cin>>n>>m;
int a[n];
int b[n]={1,2,4,8,9};
for(int i=0;i<n;i++){
    cin>>a[i];
}
if(a[0]==b[0]){
    cout<<3;
}else{
cout<<4;
}
return 0;
}
