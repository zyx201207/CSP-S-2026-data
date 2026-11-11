#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010];
long long c[500010],d[500010];	
long long ans(int x,int y){
	return d[y]-d[x]-(y-x)*c[y+1];	
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m,sum=0;
	int L=0;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
		
	sort(a+1,a+n+1);
	for(int i=2;i<=n;++i){
		b[i]=a[i]-a[i-1];
		sum+=b[i];
	}
	c[2]=sum;
	for(int i=3;i<=n;++i){
		c[i]=c[i-1]-b[i-1];
	}
	for(int i=2;i<=n;++i){
		d[i]=d[i-1]+c[i];
	} 
	int head=1,tail=1;
	while(tail<=n){
		long long num=ans(head,tail);
		if(num>m)head++;
		else{	
			L=max(L,tail-head+1);
			tail++;
		}
	}
	cout<<L;
} 
