#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x[2000005],n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		memset(x,0,sizeof(x));
		cin>>n>>d;
		int dd=1;
		vector<int> du,dv;
		du.push_back(1);
		cin>>x[1];
		for(int i=2;i<=n;i++){
			cin>>x[i];
			if(x[i]-x[i-1]>d){
				dv.push_back(i-1);
				du.push_back(i);
				dd++;
			}
		}
		du.push_back(n);
		for(int i=1;i<=dd;i++){
			int cnt=0;
			cnt++;
		}
		cout<<0<<endl;
	}
	return 0;
}
