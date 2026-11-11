#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,i,j,kk,s,rr;
	cin>>c>>n>>m>>d>>q;
	int k[n+10];
	long long w[m+10];
	long long l[n+10][n+10],r;
	vector<int>a[n+10];
	vector<long long>t[n+10];
	vector<int>o[m+10];
	map<int,long long>u[n+10];
	for(i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(j=0;j<k[i];j++){
			scanf("%d",&s);
			scanf("%lld",&r);
			a[i].push_back(s);
			t[i].push_back(r);
			o[s].push_back(i);
			u[i][s]=r;
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			l[i][j]=1ll<<60;
			if(i==j) l[i][j]=0;
		}
	}
	for(i=1;i<=m;i++){
		for(j=0;j<o[i].size()-1;j++){
			for(kk=j+1;kk<o[i].size();kk++){
				l[o[i][j]][o[i][kk]]=min(l[o[i][j]][o[i][kk]],u[o[i][j]][i]+u[o[i][kk]][i]);
				l[o[i][kk]][o[i][j]]=l[o[i][j]][o[i][kk]];
			}
		}
	}
	for(j=1;j<=n;j++){
		for(i=1;i<=n;i++){
			for(kk=1;kk<=n;kk++){
				l[j][kk]=min(l[j][kk],l[j][i]+l[i][kk]);
			}
		}
	}
	for(i=0;i<q;i++){
		long long ans=1ll<<60;
		scanf("%d",&s);
		scanf("%d",&rr);
		for(int jj : o[s]){
			for(int kkk : o[rr]){
				ans=min(ans,w[s]+w[rr]+u[jj][s]+u[kkk][rr]+l[jj][kkk]);
			}
		}
		printf("%lld\n",ans); 
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
