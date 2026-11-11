#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1];
	for(int i=0;i<n;i++){
		cin>>a[i];
}
int c=0,d=0;

for(int i=0;i<=m;i++){
c+=a[i];	
}
for(int i=0;i<=m;i++){
	d+=a[i];
	int b=c-d+5;
if(b%i==0)	{
	cout<<i;
}else{
	cout<<" 1";
}
}
}
