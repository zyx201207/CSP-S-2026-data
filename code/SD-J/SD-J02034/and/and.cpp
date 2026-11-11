#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200050],sum=1,ans,l,r;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	ans=a[m-1];
	l=m-2;
	r=m;
	while(sum<m){
		if(ans&a[l]>=ans&a[r]){
			ans=ans&a[l];
			l--;
		}else{
			ans=ans&a[r];
			r++;
		}
		sum++;
	}
	cout<<ans;
	return 0;
}
