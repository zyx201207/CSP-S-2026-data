#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF=0x3f3f3f3f;
const int MX=2e6+5;


int n,d;
int x[MX];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		bool flag=0;
		for(int i=0;i<n;i++){
			cin>>x[i];
			if(x[i]-x[i-1]>d)flag=1;
		}
		if(flag){cout<<0;continue;}
		
		cout<<"0";
	}
	return 0;
}
