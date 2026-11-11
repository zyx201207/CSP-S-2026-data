#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500015];
long long ans=0;
int main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	int ans=0;
	int cnt=0;
	long long mn;
	while(m>=ans){
		mn=1000000000015;
		for(int i=1;i<=n;i++){
			mn=min(mn,(long long)a[i]);
		}
		for(int i=1;i<=n;i++){
			if(a[i]==mn)cnt++;
		}for(int i=1;i<=n;i++){
			if(a[i]==mn)a[i]++;
		}m-=cnt;
		ans=max(ans,cnt);
	}cout<<ans;
	fclose(stdin);fclose(stdout);
	return 0;
}
