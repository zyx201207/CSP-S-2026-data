#include<bits/stdc++.h>
using namespace std;
long long n,m,t=0,s=0,c=0,p=0;
queue<stack>  q;
int a[200001];
void xuan(long long i,long long v){
	if(v==0){
		s=max(s,t);
		return;
	}
	for(int j=i;j<=n;j++){
		v--;
		t=t&q[j];
		xuan(j,v);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	p=m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		while(a[i]>0){
			q[i].push(a[i]%2);
			a[i]/=2;
		}
	}
	for(long long i=1;i<=n;i++){
		t=q[i];
		p--;
		xuan(i,p);
		c=max(c,s);
		s=0;
		t=0;
		p=m;
	}
	cout<<a[1];
	return 0;
}