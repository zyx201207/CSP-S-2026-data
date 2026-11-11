#include<bits/stdc++.h>
using namespace std;
long long cha[5000050],a[5000050];
long long n,m,cnt,ans;
int  main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;++i){
		cha[i]=a[i+1]-a[i];
	}
	long long v=0;
	for(int j=1;j<=n;++j){
		for(int i=j;i<=n;++i){
			v+=cha[i]*i;
			if(v<=m){
				cnt++;
			}
			else {
				ans=max(ans,cnt);
				cnt=0;
				v=0;
			}
		}
	}
	cout<<ans+1;
	fclose(stdin);
	return 0;
}
