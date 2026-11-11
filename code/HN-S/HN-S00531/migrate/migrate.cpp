#include<bits/stdc++.h>
using namespace std;
long long a,z1,b,t[100000][2],k[100005][2000005],z[1000005][10000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>a>>b;
	for(long long i=0;i<b;i++){
		cin>>t[i][0]>>t[i][1];
		cin>>k[i][0];
		for(long long j=1;j<t[i][0];j++){
			cin>>k[i][j];
			long long q=k[i][j]-k[i][0]-t[i][1];
			if(q<t[i][1]){
				z1++;
			}
		}
		cout<<z1<<endl;
		z1=0;
		
	}
	
	return 0;
}
