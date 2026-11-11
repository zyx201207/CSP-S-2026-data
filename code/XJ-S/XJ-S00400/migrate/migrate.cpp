#include<bits/stdc++.h>
using namespace std; 
int c,t,cnt=0;
int n,d;
int x[10000];
int main()
{
	freopen("migrate.in","r",sidin);
	freopen("migrate.out","w",sidout);
	cin>>c>>t>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(x[i]-x[j]<=d){
				continue;
			}
		}
	}
	cnt++;
	cout<<cnt;
	return 0;
}
