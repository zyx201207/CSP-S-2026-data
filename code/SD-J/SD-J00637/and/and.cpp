#include<bits/stdc++.h>
using namespace std;
using LL=long long;
LL n,m,a[300005],b,v[300005],c[300005],d;
void t(){
	b=a[c[1]];
	for(int i=2;i<=m;i++){
		b=b&a[c[i]];
	}
	d=max(b,d);
}
void f(LL x){
	if(x>m){
		t();
		return ;
	}
	if(x<=0||x>m){
		return ;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			c[x]=i;
			x++;
			f(x);
			x--;
			c[x]=0;
			v[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	b=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			b=max(b,a[i]);
		}
		cout<<b;
	}else if(m==n){
		b=a[1];
		for(int i=2;i<=n;i++){
			b=b&a[i];
		}
		cout<<b;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					b=a[i]&a[j];
					d=max(b,d);
				}
			}
		}
		cout<<d;
	}else if(n<=20){
		f(1);
		cout<<d;
	}else{
		sort(a+1,a+n+1);
		b=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			b=b&a[i];
		}
		cout<<b;
	}
	return 0;
}
//Trick||Treat!
