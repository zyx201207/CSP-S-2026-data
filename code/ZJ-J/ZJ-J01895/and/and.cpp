#include<bits/stdc++.h>
using namespace std;
int n,m,ans,d; int sh[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>sh[i];
	}
	sort(sh+1,sh+n+1);
	ans=sh[n];
	while(m--){
		ans&=sh[n-d];
		d++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}