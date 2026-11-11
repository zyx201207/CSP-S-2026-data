#include<bits/stdc++.h>
using namespace std;
int a[10002][10002];
int main(){
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++){
			cin>>a[i][j];
		}
	}
	int min=10000;
	for(int i=0;i<n;i++){
		int tmp=(a[i][1]-a[i][0])/ks;
		if(tmp<min){
			min=tmp;
		}
		tmp=10000;
	}
	cout<<min;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
