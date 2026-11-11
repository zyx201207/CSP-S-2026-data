#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt,maxv=-1,a[500100];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=abs(a[i]);
	}
	sort(a+1,a+n+1);
	long long l=1,r=1;
	while(r<=n){
		if(cnt+a[r]>m){
			cnt-=a[l];
			l++;
		}else if(cnt+a[r]<m){
			r++;
			cnt+=a[r];
		}else{
			cnt-=a[l];
			l++;
			r++;
			cnt+=a[r];
		}
		maxv=max(maxv,r-l+1);
	}
	cout<<maxv;
	return 0;
}
