#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
vector<int>a;
int main(){
	int i,j;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		int x;
		cin>>x;
		a.push_back(x);
	}
	for(j=29;j>=0;j--){
		sort(a.begin(),a.end(),greater<int>());
		for(i=0;i<a.size();i++)if(a[i]<(1<<j))break;
		i--;
		if(i+1>=m){
			 while(a.size()>i+1)a.pop_back();
			 ans+=(1<<j);
		}
		for(;i>=0;i--)a[i]-=(1<<j);
	}
	cout<<ans;
	return 0;
}
