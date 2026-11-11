#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+1;
ll d,x[N];
int c,T,n;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while (T--){
		memset(x,0,sizeof(x));
		cin>>n>>d;
		for (int i=1;i<=n;i++){
			cin>>x[i];
		}
		int s=0;
		for (int i=1;i<=n-3;i++){
			int j=i+3;
			if (abs(x[j]-x[i])>d){
				s++;
			}
		}
		cout<<s<<"\n";
	}
	return 0;
} 