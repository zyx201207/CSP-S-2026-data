#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],s[500010],ans;
bool check(int l,int r){
	long long sum=(r-l)*a[r]-(s[r-1]-s[l-1]);
	if(sum<=m) return 1;
	else return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	
	for(int i=1;i<=n;i++){
		int l=i,r=n,mid=(r+l)/2;
		while(l<r){
			mid=(r+l)/2;
			if(mid==l||mid==r){
				if(check(i,r)){
					mid=r;
				}
				break;	
			}
			if(check(i,mid)){
				l=mid;
			}
			else{
				r=mid;
			}
		}
		ans=max(ans,(long long)(mid-i+1));
		//cout<<ans<<": "<<i<<" "<<mid<<endl;
	}
	cout<<ans<<endl;
	
	
	
	
	
	return 0;
}
