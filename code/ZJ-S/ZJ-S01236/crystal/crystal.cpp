#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n;
unsigned long long m;
long long a[N];
bool check(int x){
	long long p=a[x];
	unsigned long long need=0;
	for(int i=1;i<=x;i++){
		if(a[i]<=p) need+=(p-a[i]);
	}
	if(need<=m) return true;
	else return false;
}
bool cmp(long long x,long long y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	int l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	printf("%d",l-1);
	return 0;
}