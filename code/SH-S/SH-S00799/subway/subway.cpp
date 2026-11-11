#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[600000],lne[600][600];
struct ln{
	long long nt,le;
};
long long me(long long a,long long b){
	if(a==-1){
		return b;
	}
	return min(a,b);
}
vector<ln> nl[600000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		int k,a,t;
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>a>>t;
			ln ca;
			ca.nt=i;
			ca.le=t;
			nl[a].push_back(ca);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			lne[i][j]=-1;
		}
		lne[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		int len=nl[i].size();
		for(int j=0;j<len;j++){
			for(int ki=j+1;ki<len;ki++){
				long long nj=nl[i][j].nt,nk=nl[i][ki].nt;
				lne[nj][nk]=me(lne[nj][nk],nl[i][j].le+nl[i][ki].le);
				lne[nk][nj]=lne[nj][nk];
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(lne[i][j]==-1||i==j){
				continue;
			}
			for(int ki=0;ki<n;ki++){
				if(lne[j][ki]!=-1){
					lne[i][ki]=me(lne[i][ki],lne[i][j]+lne[j][ki]);
				}
				if(lne[i][ki]!=-1){
					lne[j][ki]=me(lne[j][ki],lne[i][j]+lne[i][ki]);
				}
				lne[ki][i]=lne[i][ki];
				lne[ki][j]=lne[j][ki];
			}
		}
	}
	for(int ti=0;ti<q;ti++){
		long long x,y,ans=-1;
		cin>>x>>y;
		for(int j=0;j<nl[x].size();j++){
			for(int ki=0;ki<nl[y].size();ki++){
				ans=me(ans,nl[x][j].le+nl[y][ki].le+lne[nl[x][j].nt][nl[y][ki].nt]);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
