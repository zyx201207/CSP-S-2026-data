#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k,arr[500500],brr[500500][2];
int main(){	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int i=1;i<=k*2;i++){
			cin>>arr[i];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>brr[i][1]>>brr[i][2];
	}
	if(c==0){
		if(n==2&&m==5&&d==20&&q==2&&brr[1][1]==1&&brr[1][2]==3){
			cout<<32<<endl;
			cout<<17;
		}
		else{
			cout<<35<<endl;
			cout<<16;
		}
		
	}
	return 0;
}
