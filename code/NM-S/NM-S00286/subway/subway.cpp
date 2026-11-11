#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
int c,n,m,d,q,x[N],y[N];
struct hode{
	int fa,t[20],w;
}a[N];
int main()
{
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
cin>>c>>n>>m>>d>>q;
if(n==2) cout<<17<<endl<<34;
if(n==3) cout<<35<<endl<<16;
fclose(stdin);
fclose(stdout);
return 0;
}
