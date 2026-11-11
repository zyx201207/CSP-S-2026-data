#include<bits/stdc++.h>
using namespace std;
long long a[500010];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool f=0;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	
	long long maxs=0;
	for(int i=1;i<n;i++){
		while(a[i+1]==a[i]) i++; 
		maxs+=(a[i+1]-a[i])*i;
		if(maxs>m){//下一次不行 
			int q=i;
			long long s=a[i];
//			for(int j=i+1;j<=n;j++) if(a[j]==s)q++;
			cout<<q;
			f=1;
			break;
		}
		
	}
	if(!f) cout<<n;
	return 0;
}
