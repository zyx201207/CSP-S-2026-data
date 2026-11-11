#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long maxn=0;

struct node{
	long long v;
}a[500005];

bool cmp(node x,node y){
	return x.v<y.v;
}

bool check(long long e){
	long long sum=0;
	long long x=0;
	for(int j=e;j>=1;j--){
		sum=sum+(a[e].v-a[j].v);
		x+=1;
	}
	if(sum<=m){
		maxn=max(maxn,x);
		return true;
	}
	else{
		return false;
	}
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].v;
	}
	sort(a+1,a+n+1,cmp);
	int l=1,r=n;
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<maxn;
	return 0;
}
