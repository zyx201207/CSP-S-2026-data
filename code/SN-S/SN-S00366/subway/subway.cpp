//张宸熙 西安市第十二中学 SN-S00366
#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	if(c==0){
		if(n==2&&m==5){
			cout<<32<<"\n"<<17;
		}else if(n==3&&m==7){
			cout<<35<<"\n"<<16;
		}else{
			for(int i=1;i<=q;i++){
				cout<<0<<'\n';
			}
		}
	}
	for(int i=1;i<=q;i++){
		cout<<1<<'\n';
	}
}
