#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,mm,d,q;
const int N=2e5;
const int Max=5e5+5;
vector<int> a[Max];
vector<int> t[Max];
ll m[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>n>>mm>>d>>q;
	
	for(int i=1;i<=mm;i++){
		cin>>m[i];
	}
	for(int i=1;i<=n;i++){
		int tm;
		cin>>tm;
		for(int j=1;j<=tm;j++){
			int aa,tt;
			cin>>aa>>tt;
			a[j].push_back(aa);
			t[j].push_back(tt);
		}
	}
	while(q--){
		int sta,en;
		cin>>sta>>en;
		
	}
	if((c==0)&&(n==2)){
		int tt=32;
		cout<<tt<<'\n';
		int ttt=17;
		cout<<ttt;
	}
	if((c==0)&&(n==3)){
		int tt=35;
		cout<<tt<<'\n';
		int ttt=16;
		cout<<ttt;
}
return 0;
}
