#include<bits/stdc++.h>
using namespace std;
int place[300010],order[500010],n,m,ans[300010],nl;
vector<int>vec[500010];
stack<int>st;
int pwo(int c){return ((c%2==0)?1:-1);}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>order[i];
	st.push(order[1]);
	vec[order[1]].push_back(1);nl=1;
	place[order[1]]=1;
	for(int i=2;i<=n;i++){
		if(!place[order[i]]){
			place[order[i]]=++nl;
			vec[order[i]].push_back(i);
			st.push(order[i]);
		}else{
			for(int j=place[order[i]]+1;j<nl;j++){
				int a=st.top();
				vec[a].push_back(i);
				place[a]=0;
				st.pop();
				cout<<a<<" ";
			}
			nl=place[i];
			cout<<'\n';
		}
	}
	cout<<'\n'<<'\n';
	for(int i=1;i<=m;i++){
		for(int j=0;j<vec[i].size();j++){
			ans[i]+=pwo(j)*(n-vec[i][j]+1);
			cout<<vec[i][j]<<"!"<<ans[i]<<" ";
		}
		cout<<ans[i]<<"\n";
	}
	return 0;
}
