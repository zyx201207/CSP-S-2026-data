#include<bits/stdc++.h>
using namespace std;
const int M=3e5+5,N=5e5+5;
int n,m,a[N],b[N];
struct jg{
	int id,s;
};
vector<jg>v[M];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>0;i--){
		if(v[a[i]].size()==0){
			v[a[i]]=v[a[i+1]];
			jg t;t.id=a[i],t.s=1;
			v[a[i]].push_back(t);
		}
		else for(int i=1;i<=v[a[i]].size();i++)b[v[a[i]][i].id]+=v[a[i]][i].s;
	}
	for(int i=1;i<=m;i++)cout<<b[i]<<" ";
	return 0;
}