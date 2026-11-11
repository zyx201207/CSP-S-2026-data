#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d;int x[100100],b[5001],ci[5001][5001];
vector<int>va[100100];
queue<int>q;
void bfsc(int l){
	q.push(l);b[l]=0;
	while(!q.empty()){
		int xx=q.front();q.pop();
		for(int i=0;i<va[xx].size();i++){
			if(b[va[xx][i]]<b[xx]+1)continue;
			if(b[va[xx][i]]==b[xx]+1)ci[l][va[xx][i]]++;
			if(b[va[xx][i]]>b[xx]+1)ci[l][va[xx][i]]=1;
			b[va[xx][i]]=b[xx]+1;q.push(va[xx][i]);
		}
	}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int hg=1;hg<=t;hg++){
		
		cin>>n>>d;for(int i=1;i<=n;i++)va[i].clear();
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d)va[i].push_back(j);
			}
		}
		for(int i=1;i<=n;i++){
			for(int i=1;i<=5000;i++)b[i]=1e18;
			bfsc(i);
		}int s=0;
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				if(ci[i][j]==2)s++;
			}
		}cout<<s<<"\n";
		memset(ci,0,sizeof ci);
//		int c=1;
//		for(int i=2;i<=n;i++){
//			while(a[i]-a[c]>d)c++;
//			if(a[i]-a[c]<=d&&i!=c){
//				va[c].push_back(i);
//			}
//				
//		}
	}










	return 0;
}

