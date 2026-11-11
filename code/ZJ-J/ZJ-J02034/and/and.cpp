#include<bits/stdc++.h>
using namespace std;
long long m,n,a[2000001],cnt,ans;

struct node{
	long long to=0;
	long long used=0;
}tree[2000001][2];
void add(long long x ){
	long long p=0;
	for(long long i=30;i>=0;i--){
		long long k=(x>>i)|0;
		tree[p][k].used++;
		x-=(k<<i);
		if(tree[p][k].to==0)
		tree[p][k].to=++cnt;
		
		p=tree[p][k].to;
	}

	
}
long long find(long long x){
	long long p=0;
	for(long long i=30;i>=0;i--){
		if(tree[p][1].to!=0){
			if(tree[p][1].used>=m)ans+=1<<i;
			p=tree[p][1].to;
		}else {
			p=tree[p][0].to;
		}
		
	}
	return ans; 
}
int main(){
	freopen("and2.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		add(a[i]);
	}
	cout<<find(m);
	
	return 0;
}