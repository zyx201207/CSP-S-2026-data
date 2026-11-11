#include<bits/stdc++.h>
using namespace std;
long long daoyu[2000006];
long long bs(int st,int ed,long long  d){
	int pre=st,ans=0,owr=st;
	for(int i=st;i<=ed;i++){
		if(i==ed){
			ans++;
			if(daoyu[i]-daoyu[pre]<=d){
				break;
			}
			else{
				ans++;
				break;
			}
		}
		if(daoyu[i]-daoyu[pre]<=d){
			owr=i;
		}
		else{
			if(owr==pre){
				return 0;
			}
			ans++;
			pre=owr;
		}
	}
	return ans;
}
bool dfs(int x,int y,long long mp,long long d ){
	if(mp==0&&x!=y){
		return 0;
	}
	if(x==y){
		return 1;
	}
	for(int i=x;i<=y;i++){
		if(daoyu[i]-daoyu[x]<=d){
			bool w=dfs(i,y,mp-1,d);
			if(w==1)return 1; 
		}
		else{
			break;
		}
	}
	return 0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	long long c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		long long n,d;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>daoyu[j];
		}
		if(c==11||c==12){
			long long dn=daoyu[2]-daoyu[1];
			long long dc=d/dn; 
			if(n<=3||d<2*dn||daoyu[n]-daoyu[1]<d*2-dn){
				cout<<0<<"\n";
				continue;
			}
			cout<<n-(2*dc-1)<<"\n";
			
		}
		else if(c==13||c==14){
			if(n<=3||daoyu[n]-daoyu[1]<=d){
				cout<<0<<"\n";
				continue;
			}
			int l=1,r=n,weizi=0;
			while(l<=r){
				int mid=(l+r)>>1;
				if(daoyu[mid]-daoyu[1]>d){
					r=mid-1;
				}
				else if(daoyu[n]-daoyu[mid]>d){
					l=mid+1;
				}
				else{
					weizi=mid;
					break;
				}
			}
			long long ans=0;
			for(int j=weizi;j<=n;j++){
				if(daoyu[j]-daoyu[weizi-1]<=d&&daoyu[j]-daoyu[weizi-2]>d){
					ans++;
				}
			}
			cout<<ans<<"\n";
		}
		else if(15<=c&&c<=18){
			
		}
		else if(c<=10){
			long long ans=0;
			for(int j=1;j<=n;j++){
				for(int j0=0;j0<=0;j0++){
					if(dfs(j,j0,bs(j,j0,d),d)){
						ans++;
					}
				}
			}
			cout<<ans<<"\n";
		}
	}
	
		
	
	
	
	return 0;
}