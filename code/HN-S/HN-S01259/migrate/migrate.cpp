#include<bits/stdc++.h>
using namespace std;
long long feb[2000050],a[2000050],delta[2000050];
long long n,l,cnt,ans;
int search(int b,int e){
	cnt=0;
	for(int i=1;i<l;++i){
		if((e-i-b)%l==0){
			cnt++;
		}
	}
	return cnt;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long c,t;
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>l;
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		if(a[n]-a[1]<=l){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j)	{
				if(a[j]-a[i]<=l){
					continue;
				}
				ans+=search(a[i],a[j]);
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	return 0;
}
