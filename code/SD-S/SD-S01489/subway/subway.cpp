#include<iostream>
#include<cstdio>
#include<vector> 
using namespace std;
int c,n,m,d,q;
int w[500001];
long long s[501][501];
vector<long long> l[500001],b[500001];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int ai,ti;
			cin>>ai>>ti;
			b[ai].push_back(i);
			l[ai].push_back(ti);
		}
	}
	for(int i=1;i<=m;i++){
		if(b[i].size()>1){
			for(int j=0;j<b[i].size();j++){
				for(int k=j+1;k<b[i].size();k++){
					if(s[b[i][j]][b[i][k]]==0){
						s[b[i][j]][b[i][k]]=l[i][j]+l[i][k];
						s[b[i][k]][b[i][j]]=l[i][j]+l[i][k];
					}else{
						s[b[i][j]][b[i][k]]=min(l[i][j]+l[i][k],s[b[i][j]][b[i][k]]);
						s[b[i][k]][b[i][j]]=min(l[i][j]+l[i][k],s[b[i][k]][b[i][j]]);
					}
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(!s[i][k]||!s[k][j]||i==j||i==k||j==k){
					continue;
				}
				if(s[i][j]){
					s[i][j]=min(s[i][j],s[i][k]+s[k][j]);
				}else{
					s[i][j]=s[i][k]+s[k][j];
				}
			}
		}
	}
	for(int i=0;i<q;i++){
		int x,y;
		long long ans=0;
		cin>>x>>y;
		for(int j=0;j<b[x].size();j++){
			for(int k=0;k<b[y].size();k++){
				if(b[x][j]==b[y][k]||s[b[x][j]][b[y][k]]!=0){
					if(ans==0){
						ans=s[b[x][j]][b[y][k]]+w[x]+w[y]+l[x][j]+l[y][k];
					}else{
						ans=min(s[b[x][j]][b[y][k]]+w[x]+w[y]+l[x][j]+l[y][k],ans);
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

