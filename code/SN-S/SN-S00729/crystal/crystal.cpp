#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,ans=0,a[5000],b[5000];
	cin>>n>>m;
	int mid[5000];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	sort(a+1,a+n+1);
	for(int j=1;j<=n;j++){
	mid[j]=mid[j-1]+a[j];
	}
	for(int i=1,j=1;i<=n;i++){
		int l=(i-j+1)*a[i],r=mid[i]-mid[j-1];
	if(l-r>m){
	j++;
	}
	ans=max(ans,i-j+1);
	}
		cout<<ans;
	return 0;
	
}
