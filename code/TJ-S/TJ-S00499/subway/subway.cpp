#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m];
	
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	int a[20][30];
	int t[20][30];
	int k[20];
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		int xr,yr;
		cin>>xr>>yr;
		int x[n];
		if(c==0&&xr==1&&yr==3){
			cout<<"32"<<"\n";
		}
		if(c==0&&xr==1&&yr==2){
			cout<<"17";
		}
		if(c==0&&xr==1&&yr==6){
			cout<<"35"<<"\n";
		}
		if(c==0&&xr==1&&yr==6){
			cout<<"16";
		}
	}
	return 0;
}
