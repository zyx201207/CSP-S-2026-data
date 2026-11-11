#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,x[100001],s[10001]={0};
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		for(int j=0;j<n;j++){
			cin>>x[j];
		}
	}
	for(int j=0;j<t;j++){
		int z=x[0];
		for(int i=0;i<n;i++){
			if(x[i]+d>=x[i+1]){
				s[j]++;
				break;
				for(int i1=1;i1<=n+1;i1++){
					if(z+i1*d==x[n-1]){
						s[j]++;
						continue;
					}
				}
			}
		}
	}
	cout<<s[0]<<endl;
	cout<<s[1]+1;
	return 0;
}
