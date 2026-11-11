#include<bits/stdc++.h>
using namespace std;
long long sum,ans;
int n,m;

struct qq{
	long long b;
	vector <int> c;
};
qq a[200005];
void at1(long long x,int i){
	int now=1;
	while(x){
		if(x&1){
			a[i].c.push_back(now);
		}
		now++;
		x=x>>1;
	}
}
int sort_(qq x,qq y){
	if(x.c.size()!=y.c.size()){
		return x.c.size()<y.c.size();
	}
	return x.b<y.b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].b;
		at1(a[i].b,i);
		sum=max(sum,a[i].b);
	}
	if(m==1){
		cout<<sum;
		return 0;
	}else if(m==n){
		sum=a[1].b;
		for(int i=2;i<=n;i++){
			sum=sum&a[i].b;
		}
		cout<<sum;
		return 0;
	}
	sort(a+1,a+1+n,sort_);
	sum=a[n].b;
	for(int i=n-1;i>=n-m+1;i--){
		
		sum=sum&a[i].b;
	}
	cout<<sum;
	return 0;
	
}
