#include<bits/stdc++.h>
using namespace std;
#define int long long
int x[5000005];
int geshu[5000005];
struct node{
	int k;
	int g;
	int flag;
};
node dfs(int pos,int zhong,int dd,node tan){
	if(pos==zhong){
		tan.flag=1;
		return tan;
	}
	int minn=0x3f3f3f3f;
	int gg=0;
	int ff=0;
	for(int i=pos+1;i<=zhong;i++){
		
		if(x[i]-x[pos]<=dd){
			node tant;
			tant.k=tan.k+1;
			tant.g=tan.g;
			tant.flag=tan.flag;
			node cks=dfs(i,zhong,dd,tant);
			if(cks.flag==1&&cks.k<minn){
				ff=1;
				minn=cks.k;
				gg=1;
			}
			else if(cks.flag==1&&cks.k==minn){
				ff=1;
				gg++;
			}
		}
		
	}
	node tantt;
	tantt.g=gg;
	tantt.k=minn;
	tantt.flag=ff;
	return tantt;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int ans=0;
		int n,d;
		cin>>n>>d;
		int cha=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		cha=x[2]-x[1];
		for(int i=1;i<n;i++){
			if(cha!=x[i+1]-x[i]){
				cha=0;
			}
		}
		if(cha!=0){
			int foot=d/cha;
			if(foot==1||foot==0){
				cout<<0<<endl;
				continue;
			}
			if(n-(foot+foot-1)+1<0){
				cout<<0<<endl;
				continue;
			}
			cout<<n-(foot+foot-1)<<endl;
//			for(int i=1;i<=n;i++){
//				
//			}
		}
		else{
			for(int i=1;i<=n;i++){
				
				for(int j=i+1;j<=n;j++){
					node st;
					st.g=0;
					st.k=0;
					st.flag=0;
					node res=dfs(i,j,d,st);
					if(res.g==2){
						ans++;
//						cout<<i<<" "<<j<<endl;
					}
				}
				
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
