#include<bits/stdc++.h>
using namespace std;
struct way
{
	int cnt;
	int qwe[20010];
	int w[20010];
} a[510];
struct asd
{
	int cnt=0,in;
	int y[20010];
	int ot[20010];
} ;
vector<asd> dian;
int c,n,m,d,q;
long long sh[20020];
queue<int> iq;
queue<int> xq;
void bfs(int x)
{
	iq.push(x);
	xq.push(0);
	memset(sh,1e9,sizeof(sh));
	while(iq.size())
	{
		for(int i=1;i<=dian[iq.front()].cnt;i++)
		{
			for(int j=1;j<=a[dian[iq.front()].y[i]].cnt;j++)
			{
				int nx=xq.front()+a[i].w[j]+(dian[iq.front()].ot[i]),ni=a[i].qwe[j];
				if(sh[ni]>nx)
				{
					iq.push(ni);
					sh[ni]=nx;
				}
			}
		}
		iq.pop();
		xq.pop();
	}
}
int main(){
	//freopen("subway.in","r",stdin);
	//
	
	
	//reopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++)
	{
		int y;
		cin>>y;
		dian[i].in=y;
		cout<<dian[i].in<<endl;
	} 
	for(int i=1;i<=n;i++)
	{
		
		cin>>a[i].cnt;
		for(int j=1;j<=m;j++)
		{
			cin>>a[i].qwe[j];
			cin>>a[i].w[j];
			dian[a[i].qwe[j]].cnt++;
			dian[a[i].qwe[j]].y[dian[a[i].qwe[j]].cnt]=i;
			dian[a[i].qwe[j]].ot[dian[a[i].qwe[j]].cnt]=a[i].w[j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		int l,r;
		cin>>l>>r;
		bfs(l);
		cout<<sh[r]+dian[l].in+dian[r].in<<endl;
	}
	return 0;
}

