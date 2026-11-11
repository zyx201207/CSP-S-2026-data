#include<bits/stdc++.h>
using namespace std;
string b[1000010],e[100010];
int a[1000010],c[1000010],d[100010];
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
long long n,i,j,v=0,q=0,t=1,m=0;
cin>>n;
for(i=1;i<=n;i++){
cin>>a[i]>>b[t];
d[i]=t;
e[i]=b[t];
t+=a[i];
v+=a[i];
}for(i=1;i<=n;i++){
	m=d[i+1]-d[i];
	for(j=d[i];j<=d[i]+m;j++){
		b[j]=e[i];
	}
}t=1;
if(v%2==0){
for(i=v;i>=v/2;i--){
	if(b[i]!=b[v-t]) q++,t++;
}}
else{
for(i=v;i>=v/2;i--){
	if(b[i]!=b[v-t]) q++,t++;
}}
//}
//for(i=1;i<=v;i++){
//	for(j=0;j<a[i];j++){
////		cout<<b[i]<<" ";
//	t++;
//	cout<<b[i];}
//}cout<<t;
cout<<q++;
return 0;
}
