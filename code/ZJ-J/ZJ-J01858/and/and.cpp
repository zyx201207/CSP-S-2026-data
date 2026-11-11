#include<bits/stdc++.h>
using namespace std;
const int N=2e5+20;
int a[N];
bool v[N][99];
vector<int> b[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		int t=a[i],j=0;
		while(t){
			v[i][++j]=t%2;
			if(t%2) b[j].push_back(a[i]);
			t/=2;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=32;j++) cout<<v[i][j];
//		cout<<"\n";
//	}
//	for(int i=1;i<=32;i++) {
//		int l=b[i].size();
//		for(int j=0;j<=l-1;j++) cout<<b[i][j]<<" ";
//		if(l) cout<<"\n";
//	}
	for(int i=32;i>=1;i--){
		int l=b[i].size();
		if(l<m) continue;
		sort(b[i].begin(),b[i].end());
		int ans=INT_MAX;
		for(int j=l-1,k=1;j>=0,k<=m;j--,k++) {
//			cout<<ans<<" & "<<b[i][j]<<" = "<<(ans & b[i][j])<<"\n";
			ans=(ans & b[i][j]);
		}
		cout<<ans;
		
		return 0;
	}
	
	return 0;
}
