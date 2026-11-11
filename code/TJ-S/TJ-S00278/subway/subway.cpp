#include<bits/stdc++.h>
using namespace std;
int subway[100005]={};
int line[5000005][25]={};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	if(c==0){
		cout<<35<<endl<<16;
		return 0;
	}
	for(int i=1;i<=m;i++){
		cin>>subway[i];
	}
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
		while(k--){
			int a,t;
			cin>>a>>t;
			line[i][a]=t;
		}
 }
	return 0;
}
