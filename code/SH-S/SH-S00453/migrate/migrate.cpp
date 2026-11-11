#include<bits/stdc++.h>
using namespace std;
int c,t;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	
	while(t){
		long long n,d,x[2000005];
		int ans=0;
		
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[n];
		}
		
		for(int v=2;v<=n;v++){
			for(int u=1;u<v;u++){
				bool g[2000005];
				int lo=u;
				for(int i=u+1;i<=v;i++){
					if(x[i]-x[lo]>d){
						lo=i-1;g[i-1]=true;
					}
				}
				lo=v;
				for(int i=v-1;i>=u;i++){
					if(x[lo]-x[i]>d){
						lo=i+1;
						if(g[i+1]){
							ans++;
							break;
						}
					}
				}
			}
		}
		
		cout<<ans<<endl;
		t--;
	}
	return 0;
}
