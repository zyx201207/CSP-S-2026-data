#include<bits/stdc++.h>
using namespace std;
long long m;
int n,l,r;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	long long cnt=0;
	for(int i=1;i<=n;i++){
		int k1=lower_bound(a+1,a+n+1,a[i])-a;
		int k2=upper_bound(a+1,a+n+1,a[i])-a;
		k2=min(k2,n+1);
		if(k2-k1>cnt){
			r=k2-1;
			l=k1;
			cnt=k2-k1;
		}
	}
	while(m>=0 && (l!=1 || r!=n)){
		long long ne=1e17;
		if(l==1){
			ne=(a[r+1]-a[r])*r;
			if(m-ne>=0) m-=ne;
			else break;
			r++;
		}
		else if(r==n){
			ne=a[l]-a[l-1];
			if(m-ne>=0) m-=ne;
			else break;
			l--;
		}
		else{
			if(a[l]-a[l-1]>((a[r+1]-a[r])*(r-l+1))){
				ne=(a[r+1]-a[r])*(r-l+1);
				if(m-ne>=0) m-=ne;
				else break;
				r++;
			}
			else{
				ne=a[l]-a[l-1];
				if(m-ne>=0) m-=ne;
				else break;
				l--;
			}
		}
	}
	cout<<r-l+1;
	return 0;
}
