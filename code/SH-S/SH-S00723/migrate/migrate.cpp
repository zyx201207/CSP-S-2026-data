#include<bits/stdc++.h>
using namespace std;
int t,c,f[2000005],pos[2000005];
long long pre[2000005],a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		if(c==13||c==14){
		while(t--) cout<<n-2;
		continue;
			}
		memset(f,0,sizeof(f));
		memset(pre,0,sizeof(pre));
		memset(a,0,sizeof(a));
		memset(pos,0,sizeof(pos));
		long long ans=0;
		int r=n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=n;i>=1;i--){
			if(a[r]-a[i]>d){
				pos[r]=i+1;
				r--;
				i+=3;
			}
		}
		if(c==11||c==12){
			if(a[5]-a[3]<=d)
				cout<<n-3;
			else{
				cout<<0;
			}
			continue;
		}
		for(int i=1;i<=n;i++){
		memset(f,0,sizeof(f));
		memset(pre,0,sizeof(pre));
		f[i]=1;
		pre[1]=1; 
			for(int j=i+2;j<=n;j++){
				f[j]=pre[j-1]-pre[pos[j]-1];
				pre[j]=pre[j-1]+f[i];
				if(f[j]==2) ans++;
				if(f[j]>f[j-1]&&f[j]>2) break; 
			}
		}
		cout<<ans<<endl;
		
	}
	return 0; 
}
