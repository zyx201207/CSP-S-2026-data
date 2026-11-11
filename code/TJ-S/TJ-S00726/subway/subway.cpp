#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int a,b,c,d,e,f[100005],g;
	cin>>a>>b>>c>>d>>e;
	for(int i=1;i<=c;i++){
		cin>>f[i];
	}
	int x;
	cin>>g>>x;
	for(int i=1;i<=e;i++){
		int asd,qwe;
		cin>>asd>>qwe;
		cout<<x*i*2+f[asd]+f[qwe];
	}
	return 0;
}
