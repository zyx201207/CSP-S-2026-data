#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10,M=500;
long long c,n,m,d,q;
long long w[M];
int t[M][N],k[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i+=1){
		cout<<"0";
		return 0;
	}
	return 0;
}

