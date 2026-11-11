#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int c,t,n,k,q[N],vis[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
		while(t--)
		{
			int n,k,u,v;
			cin>>n>>k;
			for(int i=1;i<n;i++)cin>>u>>v;
			int m=n/2;
			int c=ceil(1.0*(m-k)/4)+1;
			if(n==k)printf("0\n");
			else if(k>=m)printf("1\n");
			else printf("%d\n",c);
		}
	return 0;
}