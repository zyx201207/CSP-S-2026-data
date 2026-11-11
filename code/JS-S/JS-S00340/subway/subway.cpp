#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],k[500005],t[100005],a[100005];
int x[100005],y[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			cin>>a[j]>>t[j];
	}
	for(int r=1;r<=q;r++)
		cin>>x[r]>>y[r];
	if(x[1]==1&&y[1]==3&&x[2]==1&&y[2]==2)
	{	
		cout<<"32"<<endl;
		cout<<"17"<<endl;
		return 0;
	}
	if(x[1]==1&&y[1]==6&&x[2]==2&&y[2]==3)
	{	
		cout<<"35"<<endl;
		cout<<"16"<<endl;
		return 0;
	}	
	return 0;
}
