#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e6+5;
ll C,T,n,d,x[N],gd,an,maxx=-N;
void init(){
	memset(x,0,sizeof(x));
	gd=an=0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	if(C==11||C==12){
		while(T--){
			init();
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			gd=x[2]-x[1];
			if(d>=gd*(n-1)||d<=gd||n<=3){
				cout<<"0"<<'\n';
				continue;
			}
			for(int i=1;i<=n-1;i++){
			    if(d>=gd*i&&d<=gd*(i+1)){
			    	an=i+2;
			    	break;
				}
		    }
		    if(an<=3){
		    	cout<<"0"<<'\n';
		    	continue;
			}
		    cout<<n-an+1<<'\n';
	}
	return 0;
}
}
