#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("travel","r",stdin);
freopen("travel","w",stdout);
string q,p,m,n;
int k,l;
cin>>q>>n>>p>>m;
char a[3];
k=m.size();
a[1]=m[k-1];
k=n.size();
a[2]=n[k-1];
l=max(a[1],a[2])-min(a[2],a[1]);
if(q==p){
	cout<<1;
}else{
cout<<0<<0<<0<<0;
return 0;
}
if(l<=4){
	cout<<1;
}else{
cout<<0<<0<<0;
return 0;
}
if(a[1]+a[2]<='B'+'C'||a[1]+a[2]>='D'+'E'){
	cout<<1;
if(abs(a[1]-a[2])==1){
	cout<<1;
return 0;
}else
cout<<1;
return 0;
}else
cout<<0<<0;
return 0;
}
