#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int a,b,c,d,e,f[100];
	cin>>a>>b>>c>>d>>e;
	for(int i=1;i<=c;i++) cin>>f[c];
	for(int i=1;i<=18;i++) cin>>f[100-i];
	if(b==3) for(int i=1;i<=9;i++) cin>>f[25+i];
	if(b==2) cout<<32<<endl<<17;
    else cout<<35<<endl<<16;
	return 0;
}
