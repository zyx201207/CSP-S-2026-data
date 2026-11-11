#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],ans,s[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	bool f=true;
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			f=false;
			break;
		}
	}
	if(f){
		int x=sqrt(m*2);
		while(x*(x+1)/2<m)x++;
		while(x*(x+1)/2>m)x--;
		cout<<min(x+1,n);
		return 0;
	}
	f=true;
	int d=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=d){
			f=false;
			continue;
		}
	}
	if(f){
		m/=d;
		int x=sqrt(m*2);
		while(x*(x+1)/2<m)x++;
		while(x*(x+1)/2>m)x--;
		cout<<min(x+1,n);
		return 0;
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i-1,cnt=1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[i]*(i-mid)-s[i-1]+s[mid-1]<=m){
				cnt=max(cnt,i-mid+1);
				r=mid-1;
			}
			else l=mid+1;
		}
		ans=max(ans,cnt);
//		cout<<ans<<" "<<cnt<<endl;
	}
	cout<<ans;
	return 0;
}
