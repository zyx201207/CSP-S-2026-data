#include<bits/stdc++.h>
using namespace std;
int n,m;
int maxidx=0;
long long a[200010];
long long dis(long long x){
	int l=log2(x);
	if(x-((1<<l)-1)<=((1<<(l+1))-1)-x)
		return x-((1<<l)-1);
	else
		return (1<<(l+1))-x;
}
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		long long maxn=0;
		for(int i=0;i<n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}else if(m==2){
		long long maxn=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
		return 0;
	}else if(m==n){
		long long maxn=a[0];
		for(int i=0;i<n;i++){
			maxn&=a[i];
		}
		cout<<maxn;
		return 0;
	}
	sort(a,a+n,cmp);	
	for(int i=0;i<n;i++){
		if(dis(a[maxidx])>dis(a[i]))
			maxidx=i;
		else if(dis(a[maxidx])==dis(a[i])&&a[i]>a[maxidx])
			maxidx=i;
	}
	long long ans=a[0];
	for(int i=1;i<m;i++){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
