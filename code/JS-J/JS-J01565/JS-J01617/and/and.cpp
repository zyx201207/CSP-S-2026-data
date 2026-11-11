#include<bits/stdc++.h>
using namespace std;
int a[200005],f[200005][33];
vector<int> g,g2;
int n,m,maxx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n;++i){
		int x=a[i],cnt=0;
		while(x){
			f[i][++cnt]=x%2;
			x/=2;
		}
		maxx=max(maxx,cnt);
	}
	int ans=0,j=maxx;
	for(int i=1;i<=n;i++) g.push_back(i);
	while(j>0){
		int tot=0;
		g2.clear();
		for(int i:g){
			if(f[i][j]==1) tot++; 
		}
		if(g.size()==0){
			ans*=2;
			j--;
			continue;
		}
		if(tot>=m){
			ans=ans*2+1;
			for(int i:g){
				if(f[i][j]==0){
					g2.push_back(i);
				}
			}
			for(int v:g2){
				for(int i=1;i<=32;i++) f[v][i]=0;
			}
		}
		else{
			ans*=2; 
		}
		j--;
	}//tanxin??
	//i use dp to write 1 hour
	//gg
	//i am UT ru
	//i love play phigros
	//feropen mian
	//wo cai 3 sui
	//2026 csp-j mi huo xing wei da shang hui you wo ma
	cout<<ans;
	return 0;
}

