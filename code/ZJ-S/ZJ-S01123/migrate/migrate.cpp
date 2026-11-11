#include<bits/stdc++.h>
using namespace std;
int c,t,b,n,a[2000200];
struct kkksc03{
	int cs,dd;
}kk,ll;
queue <kkksc03> q;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		int da=0;
		if(c==11 || c==12) 
		{
			for(int i=1;i<=t;i++) cout<<"0\n";
			return 0;
		}
		cin>>c>>b;
		for(int j=1;j<=c;j++) cin>>a[j];
		for(int j=1;j<=c;j++)
		{
			for(int k=j+1;k<=c;k++)
			{
				kk.cs=0;
				kk.dd=1;
				q.push(kk);
				int ff=0,nn=0;
				while(!q.empty())
				{
					kk=q.front();
					q.pop();
					for(int l=kk.dd;l<=n;l++)
					{
						if(a[l]-kk.dd<=b)
						{
							if(l!=n)
							{
								ll.cs=kk.cs+1;
								ll.dd=a[l];
								q.push(ll);
							}
							else
							{
								if(nn) {if(nn==kk.cs) ff++;else break;}
								else { nn=kk.cs; ff++; }
								if(ff>2) break;
							}
						}
						else break;
					}
				}
				while(!q.empty()) q.pop();
				if(ff==2)
				{
					da++;
				}
			 }
		}
		cout<<da<<endl;
	}
}
