#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;long long m;
	cin>>n>>m;
	vector<long long>a(n+1);
	vector<long long>s(n+1);
	s[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin()+1,a.end());
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	
	int l=1,r=1;
	int ans=-1;
	while(l!=n){
		long long w=(r-l+1)*a[r]-(s[r]-s[l-1]);
		if(w>m){
			l++;
			continue;
		}
		ans=max(r-l+1,ans);
		if(r<n)r++;
		else l++;
	}
	cout<<ans<<endl;
	return 0;
}
