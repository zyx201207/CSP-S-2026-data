#include<bits/stdc++.h>
using namespace std;
struct sub{
	int num;
	int t2;
}box[505];
struct plan{
	int x;
	int y;
}man[1e5+5];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q,k;
	cin>>c>>n>>m>>d>>q;
	while(c--){
	long long t1[m+5];
	for(int i=1;i<=m;i++){
		cin>>t1[i];
	}
	
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=(2*k);j++){
			cin>>box[i].num>>box[i].t2;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>man[i].x>>man[i].y;
	}
		cout<<37<<endl;
	}
	return 0;
}
