#include<bits/stdc++.h>
using namespace std;
long long n,m,b[25000005],sum,ok=0,k,e;
struct node{
	int a,s;
}c[25000005];
bool cmp(node x,node y){
	if(x.s==y.s){
		return x.a<y.a;
	}
	else{
		return x.s>y.s;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		c[i].a=0;
		c[i].s=1;
	}
	ok=n;
	k=1;
	for(int i=n;i>=2;i--){
		for(int j=i-1;j>=1;j--){
			k++;
			ok++;
			if(j==i-1){
				c[ok].a+=b[i]-b[j];
			}
			else{
				c[ok].a+=b[i]-b[j]+c[ok-1].a;
			}
			c[ok].s=k;
		}
		k=1;
	}
	sort(c+1,c+ok+1,cmp);
	for(int i=1;i<=ok;i++){
		if(c[i].a<=m){
			cout<<c[i].s;
			return 0;
		}
	}
	return 0;
}
