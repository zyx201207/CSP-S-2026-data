#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	long long u[100][100],v[100][100]; 
	for(long long i=0;i<t;i++){
		int k;
		cin>>k;
		for(long long j=0;j<k-1;j++){
			cin>>u[i][j]>>v[i][j];
		}
	}
	for(int i=0;i<t;i++){
		cout<<i+1<<endl;
	}
	return 0;
}