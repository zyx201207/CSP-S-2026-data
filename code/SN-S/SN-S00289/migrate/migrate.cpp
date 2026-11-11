#include<bits/stdc++.h>
using namespace std;
struct node{
	int to,ti;
};
int w[50][500000+5];//w[0][i]第i站进出站，1第i站1号线，2 2号线 
 vector<node> sta[500000+5];
set<int> set1;set<int> s1;set<int> s2;
int ans=1000000000+7;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	int c, n, m, d, q;
	cin>>c>>n>>m>>d>>q;
	if(c==20||c==21){
		for(int i=1;i<=500000+5;i++){
			w[1][i]=1000000000+7;w[2][i]=1000000000+7;
		}
		for(int i=1;i<=m;i++){
			cin>>w[0][i];
		}
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++){
				int a;cin>>a;
				cin>>w[i][a];
				s1.insert(a);
				s2.insert(a);
			}
		}
		for(int i=1;i<=m;i++){
			if(s1.find(i)!=s1.end()&&s2.find(i)!=s2.end())set1.insert(i);
		}
		int mn=1000000000+7;
		for(int i=1;i<=m;i++){
			if(set1.find(i)!=set1.end())mn=min(w[1][i]+w[2][i],mn);
		}
		for(int i=1;i<=q;i++){
			int fr,to;
			cin>>fr>>to;
			if(s1.find(fr)!=s1.end()&&s1.find(to)!=s1.end())
				cout<<w[0][fr]+w[0][to]+min(w[1][fr],w[2][fr])+min(w[1][to],w[2][to])<<'\n';
			else if(s2.find(fr)!=s2.end()&&s2.find(to)!=s2.end())
			    cout<<w[0][fr]+w[0][to]+min(w[1][fr],w[2][fr])+min(w[1][to],w[2][to])<<'\n';
			else if(s1.find(fr)!=s1.end()&&s2.find(to)!=s2.end())
				cout<<w[0][fr]+w[0][to]+min(w[1][fr],w[2][fr])+min(w[1][to],w[2][to])+mn<<'\n';
			else if(s2.find(fr)!=s2.end()&&s1.find(to)!=s1.end())
				cout<<w[0][fr]+w[0][to]+min(w[1][fr],w[2][fr])+min(w[1][to],w[2][to])+mn<<'\n';
		}
	}else {
		for(int i=1;i<=m;i++){
			cin>>w[0][i];
		}
		for(int i=1;i<=n;i++){
			int k,cnt=0;
			cin>>k;
			for(int j=1;j<=k;j++){
				int st,tim;
				cin>>st>>tim;
				w[i][cnt++]=st;
				
			}
		}
		for(int i=1;i<=q;i++){
			int fr,to;
			cin>>fr>>to;
		}
	}
	return 0;
}
