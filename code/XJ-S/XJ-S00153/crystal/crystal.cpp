#include<bits/stdc++.h>
using namespace std;
int n,m,l=1,a[500010],r=1,maxn,mocha,c1=1;
long long int ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	while(1){
		r++;
		if(ans>m){
			maxn=max(maxn,r-l-1);
			l++;
			r--;
			if(l==r)r++;
			else{
				mocha-=(a[c1+1]-a[c1]);
				c1++;
			}
			ans-=mocha;
			
		}
		ans=ans+(r-l)*(a[r]-a[r-1]);
		mocha+=a[r]-a[r-1];
		if(r==n)break;
	}
	maxn=max(maxn,r-l);
	cout<<maxn;
	return 0;
} 
