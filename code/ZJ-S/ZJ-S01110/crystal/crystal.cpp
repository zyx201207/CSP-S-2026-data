#include<bits/stdc++.h>
using namespace std;
long long n,m,t,w,mid,bao,a[1000010],b[1000010];
bool pd(int x){
	long long mi=2e18,s;
	for(int i=x;i<=n;i++){
		s=b[i]-b[i-x+1]+a[i-x+1]*(i-x)-a[i]*(i-x);
		mi=min(mi,s);
	}
	return mi<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		b[i]=(a[i]-a[i-1])*(i-1)+b[i-1];
	}
	t=1;w=n;
	while(t<=w){
		mid=(t+w)/2;
		if(pd(mid)){
			t=mid+1;bao=mid;
		}
		else{
			w=mid-1;
		}
	}
	cout<<bao;
	return 0;
}