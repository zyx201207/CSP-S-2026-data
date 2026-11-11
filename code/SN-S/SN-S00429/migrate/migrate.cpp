#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=5e3+5;
int c,t;
int a[maxn];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(a[2]-a[1]>d/2){
			cout<<0;
			continue;
		}else{
			cout<<n/2<<endl;
		}
	}
	return 0;
}

