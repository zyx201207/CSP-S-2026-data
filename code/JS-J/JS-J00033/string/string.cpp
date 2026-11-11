#include <bits/stdc++.h>
using namespace std;
#define int long long
struct T{
	int p;
	char c;
};
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	vector<T>a(n+1,{0,0});
	vector<T>b(n+1,{0,0});
	for(int i=1;i<=n;i++){
		cin>>a[i].p>>a[i].c;
		b[n-i+1].p=a[i].p;
		b[n-i+1].c=a[i].c;
	}
	int i=1,j=1,sum=0;
	while(i<=n&&j<=n){
		if(a[i].c!=b[j].c){
			int w=min(a[i].p,b[j].p);
			sum+=w;
			a[i].p-=w;
			b[j].p-=w;
			if(a[i].p==0)i++;
			if(b[j].p==0)j++;
		}
		else{
			int w=min(a[i].p,b[j].p);
			a[i].p-=w;
			b[j].p-=w;
			if(a[i].p==0)i++;
			if(b[j].p==0)j++;
		}
	}
	cout<<sum/2;
	/*
	int i=1,j=1;
	while(i<=n&&j<=n){
		if(a[i].c==b[j].c){
			if(a[i].p>b[j].p){
				a[i].p-=b[j].p;
				j++;
			}
			if(a[i].p==b[j].p){
				i++;
				j++;
			}
			if(a[i].p<b[j].p){
				b[j].p-=a[i].p;
				i++;
			}
		}
		else{
			if(a[i].p>b[j].p){
				sum+=b[j].p;
				a[i].p-=b[j].p;
				j++;
			}
			if(a[i].p==b[j].p){
				sum+=a[i].p;
				i++;
				j++;
			}
			if(a[i].p<b[j].p){
				sum+=a[i].p;
				b[j].p-=a[i].p;
				i++;
			}
		}
			cout<<i<<' '<<j<<' '<<sum<<'\n';
			for(int v=i;v<=n;v++){
				cout<<a[v].p<<a[v].c;
			}
			cout<<'\n';
			for(int v=j;v<=n;v++){
				cout<<b[v].p<<b[v].c;
			}
			cout<<'\n';
	}
	cout<<sum;
	*/
	return 0;
}
