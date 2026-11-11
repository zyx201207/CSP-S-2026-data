#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],t[30][500005],a[30][500005];
struct node{
	int ti;
	vector<int>li;
	vector<int>num;
}s[500005];
vector<int>line[30];
int main(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j];
			cin>>t[i][j];
			s[a[i][j]].li.push_back(i);
			s[a[i][j]].st.push_back(j);
			s[a[i][j]].ti=t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		//int ssi=x.lin£»
	}
	
	return 0;
}
