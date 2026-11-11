#include<bits/stdc++.h>
using namespace std;
int a[500001];
long long cnt[500001];
int q(int l,int r,int x,long long _find){
	while(l<=r){
		int mid=(l+r)/2;
		if(cnt[x]-cnt[mid]-(mid-1)*(a[x]-a[mid])>_find) l=mid+1;
		else r=mid-1;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	int _max=-1;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]&&i>1) flag=0;
		if(i>1) cnt[i]=cnt[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		cnt[i]=cnt[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			long long tm=m;
			int sum=1;
			int l=i-1;
			while(l>0){
				tm-=a[i]-a[l];
				l--;
				if(tm<0) break;
				sum++;
			}
			if(sum>_max) _max=max(sum,_max);
		}
		cout<<_max;
	}
	else{
		if(flag){
			cout<<n;
			return 0;
		}
		for(int i=1;i<=n;i++){
			int t=i-q(0,i,i,m)+1;
			_max=max(_max,t);  
		}
		cout<<_max;
	}
	return 0;
}
