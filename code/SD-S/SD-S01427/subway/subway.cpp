#include<bits/stdc++.h>
using namespace std;
const int MAXK=5e5+5;
int sum[MAXK];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,n,m,d,q;
	cin>>c;
	cin>>n>>m>>d>>q;
	vector<int>w(m+5);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x;
			cin>>x;
			sum[i]+=x;
		}
	}
	for(int i=1;i<=q;i++){
		cout<<sum[i]<<"\n";
	}
	return 0;
}
/*
直接看不懂
看力竭了 
*/ 
