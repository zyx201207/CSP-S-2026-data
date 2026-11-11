#include<bits/stdc++.h>
#define fre(name) freopen(name".in","r",stdin),freopen(name".out","w",stdout)
using namespace std;
int a,b,c,d,e;
signed main(){
	fre("subway");
	srand(time(0));
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>a>>b>>c>>d>>e;
	for(int i=1;i<=e;i++){
		cout<<rand()<<'\n';
	}
	return 0;
}