#include<bits/stdc++.h>
using namespace std;

int main(){
freopen("xxxx.in","r",stdin);
freopen("xxxx.out","w",stdout);
int n,s=1,v=0;
cin>>n;
int a[n];
int c[n];
for(int i=0;i<n;i++){
cin>>a[i];
cin>>c[i];
if(i>0 and c[i]!=c[i-1]){
s=0;
}
v+=a[i];
}
if(s==1){
cout<<0;
return 0;
}

cout<<v/2;

fclose(stdin);
fclose(stdout);
}
