#include<bits/stdc++.h>
#define int long long
using namespace std;
int no_use,ans;
map<int,int> save;

void dfs(int s,int t,vector<vector<pair<int,int> > > &v1,vector<vector<pair<int,int> > > &v2,vector<pair<int,int> > &next,int c=-1,int result=0){
	if(result>ans){
		return;
	}
	save[s]=result;
	if(s==t){
		ans=result;
		return;
	}
	int len1=next.size();
	for(int i=0;i<len1;i++){
		if(next[i].first==c){
			continue;
		}
		int len2=v2[next[i].first].size();
		for(int j=0;j<len2;j++){
			if(result<save[v2[next[i].first][j].first]||save[v2[next[i].first][j].first]==-1) dfs(v2[next[i].first][j].first,t,v1,v2,v1[v2[next[i].first][j].first],next[i].first,result+next[i].second+v2[next[i].first][j].second);
		}
	}
	return;
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int n,m,q;
	cin>>no_use>>n>>m>>no_use>>q;
	vector<int> w(m);
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	vector<int> k(n);
	vector<vector<pair<int,int> > > v1(m+1);
	vector<vector<pair<int,int> > > v2(n);
	for(int i=0;i<n;i++){
		cin>>k[i];
		vector<pair<int,int> > temp1(k[i]);
		pair<int,int> temp;
		for(int j=0;j<k[i];j++){
			cin>>temp1[j].first>>temp.second;
			temp1[j].second=temp.second;
			temp.first=i;
			v1[temp1[j].first].push_back(temp);
		}
		v2[i]=temp1;
	}
	vector<int> s(q);
	vector<int> t(q);
	for(int i=0;i<q;i++){
		cin>>s[i]>>t[i];
	}
	vector<int> result(q,0);
	for(int i=0;i<q;i++){
		for(int j=0;j<m;j++){
			save[j]=-1;
		}
		ans=1e18;
		dfs(s[i],t[i],v1,v2,v1[s[i]]);
		result[i]=ans;
	}
	for(int i=0;i<q;i++){
		cout<<result[i]+w[s[i]-1]+w[t[i]-1]<<endl;
	}
	return 0;
}
