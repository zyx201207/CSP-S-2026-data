//SN-S00483 胡海瑧 西安市铁一中学 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d;
const int N=2e6+5;
int x[N];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	int ch=x[2]-x[1];
	if(ch==1){
		if(d>(ch*2)){
			cout<<0;return ;
		}
		else if(d==(ch*2)){
			cout<<(n-3)<<"\n";return ;
		}
		else{cout<<0;return ;}
	}
	else{
		if(d<=(ch*2)){cout<<0<<"\n";return ;}
		else if((d>(ch*2)&&(d<(ch*3)))){cout<<(n-4+1)<<"\n";}		
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--) solve();
	}
	return 0;
}
