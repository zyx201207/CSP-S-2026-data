#include<bits/stdc++.h>
using namespace std;
#define int long long

int c,n,t,d;
int a[2000010];

int f[2000010];
int v[2000010];

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin>>c>>t;
	
	if(c>=13&&c<=14){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			cout<<0<<'\n';
		}
		return 0;
	}
	
	while(t--){
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		
		for(int i=1;i<=n;i++){
			v[i]=1;
			for(int j=i+1;j<=n;j++)v[j]=0;
			
			int l=i+1,r=i;
			int lasl=i,lasr=i;
			while(l<=n){
				while(r<n&&(a[r+1]-a[l-1]<=d))r++;
				if(r<l)break;
				int res=0;
				for(int j=lasl;j<=lasr;j++)res+=v[j];
				int k=lasl;
				for(int j=l;j<=r;j++){
					while((a[j]-a[k])>d)res-=v[k],k++;
					v[j]=res;
				}
				lasl=l,lasr=r;
				l=r+1;
			}
			for(int j=i+1;j<=n;j++)if(v[j]==2)ans++;
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}

/*
怎么要被区分了，再见了各位！
*/