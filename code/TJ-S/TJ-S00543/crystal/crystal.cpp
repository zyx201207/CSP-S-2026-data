#include<bits/stdc++.h>
using namespace std; 
long long n,m,a[500005],s[500005],l,r,mid,ned,ans; 
bool cmp(int o,int p){
	return o>p;
}int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=n;i>=2;i--){
		if(m>=i*a[i]-s[i]){
			ans=max(ans,(long long)(i-1));
			break;
		}l=0,r=i-1;
		while(l<r){
			mid=((l+r)>>1);
			ned=mid*a[i]-s[i-1]+s[i-1-mid];
			cout<<mid<<":"<<ned<<";";
			if(ned<=m)
				l=mid+1;
			else
				r=mid-1;	
		}
		cout<<"\n\n"<<i<<":"<<mid<<"\n\n";
		ans=max(ans,mid);
	}
	cout<<ans+1;
	return 0;
}
