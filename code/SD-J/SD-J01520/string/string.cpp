#include<bits/stdc++.h>
using namespace std;
int a[200004];
char c[200030];
long long ans,sz;
void js(int x,int y){
	if(a[x]>=a[y]){
		sz=a[y];
		a[x]=a[x]-a[y];
		a[y]=0;
	}
	else{
		sz=a[x];
		a[y]=a[y]-a[x];
		a[x]=0;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r){
		sz=0;
		js(l,r);
		if(c[l]!=c[r])
			ans=ans+sz;
		if(!a[l])
			l++;
		if(!a[r])
			r--;
	}
	cout<<ans;
}
