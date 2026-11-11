#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	int sp=0,ans=0;
	for(int i=0,j=0;j<n;){
		int len=j-i+1;
		if(sp<=m){
			j++;
			sp+=len*(a[j]-a[j-1]);
		}
		if(sp>m){
			i++;
			sp-=a[j]-a[i-1];
		}
		ans=max(ans,len);
	}
	cout<<ans;
	return 0;
}
