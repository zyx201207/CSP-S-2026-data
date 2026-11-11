#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long minn=2e18+1;
struct node
{
	int w;
	int l[505];
}a[500005];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i].w;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			int y;
			cin>>y;
			cin>>a[y].l[i];
		}
	}
	
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int lx[n+5],ly[n+5];
		
		for(int i=1;i<=n;i++)
		{
			long long num=0;
			bool tfx=false,tfy=false;
			if(a[x].l[i]>0){
				lx[i]+=1;
				tfx=true;
			}
			if(a[y].l[i]>0){
				ly[i]+=1;	
				tfy=true;
			}
			if(tfx&&tfy){
				num=a[x].l[i]+a[y].l[i];
				minn=min(minn,num); 
			}
		}
		cout<<a[x].w+a[y].w+minn;
	
	
	
	}
	return 0;
}
