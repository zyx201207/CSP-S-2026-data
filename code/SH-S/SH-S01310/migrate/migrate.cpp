#include<bits/stdc++.h>
#define int long long
#define N 5005
using namespace std;
int c,t,n,d;
int x[N];
int cal(int l,int r,int cnt){
	if(cnt==0)return 0;
	if(x[r]-x[l]<=d&&cnt==1)return 1;
	int ans=0;
	for(int i=r-1;i>=l&&x[r]-x[i]<=d;i--)ans+=cal(l,i,cnt-1);
	return ans;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		int ans=0;
		for(int i=1;i<=n;i++){
			int j=i+1;
			while(j<n&&x[j+1]-x[i]<=d){
				j++;
//				cout<<j<<endl;
			}
			if(j==n&&x[j]-x[i]<=d)break;
			for(;j<=n;j++){
				int ccc=0;
//				cout<<i<<" "<<j<<"\n";
				int now=i;
				while(now<j){
					int asdf=now;
					for(;asdf<j&&x[asdf+1]-x[now]<=d;asdf++);
					if(now==asdf)break;
//					cout<<asdf<<endl;
					now=asdf;
					ccc++;
				}
				if(now!=j)break;
				ans+=(cal(i,j,ccc)==2);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

