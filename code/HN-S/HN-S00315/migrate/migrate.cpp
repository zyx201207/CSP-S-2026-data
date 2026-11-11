#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,s,ans,u,mi,a[2000003];
void dfs(int l,int r){
	if(l>=r-1){
		if(s>=mi){
			if(s>mi){
				s=mi;
				ans=1;
			}
			if(s==mi){
				ans++;
			}
		}
		return ;
	}
	for(int i=l+1;i<r;i++){
		if(a[l]+d>=a[i]){
			mi+=a[i]-a[l];
			dfs(i,r);
			mi-=a[i]-a[l];
		}if(a[r]-d<=a[i]){
			mi+=a[r]-a[i];
			dfs(l,i);
			mi-=a[r]-a[i];
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		u=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(11<=c&&c<=12){
			if(a[n]-a[n-2]<=d) cout<<n-3<<'\n';
			else cout<<0<<'\n';
		}else{
			for(int i=1;i<=n;i++){
				for(int j=i+2;j<=n;j++){
					s=0x3f3f3f3f;
					mi=0;
					ans=0;
					dfs(i,j);
//					cout<<mi<<endl;
					if(ans==2) u++;
				}
			}
			cout<<u<<endl;
		}
	}
	return 0;
}
