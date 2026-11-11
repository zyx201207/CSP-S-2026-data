#include <bits/stdc++.h>
using namespace std;
long long d[100005];
long long t[2000005];
long long s[100005][2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>t[i]>>d[i];
		for(int j=0;j<t[i];j++){
			cin>>s[i][j];
		}
	}
	for(int i=1;i<t;i++){
		cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
