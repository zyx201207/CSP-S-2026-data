#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500005],ans;

void calc(){
	long long res=m,l=1,r=1,maxx=0,lr=1,ll=1;
	while(r<n){
		ans=max(ans,r-l+2);
		if(res>=(a[r+1]-a[l])-(a[lr]-a[ll])){
			res=a[r+1]-a[l];
			lr=r;
			r++;
		}else{
			lr=r,ll=l;
			if(res+(a[l+1]-a[l])<=m){
				res+=(a[l+1]-a[l]);
				l++;
			}else if(l==r){
				l++,r++;
			}
		}
	}
	return ;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	calc();
	cout<<ans;
	return 0;
}
