#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t){
		int n,d,x[10005];
		cin>>n>>d;
		for(int i=1;i<n;i++){
			cin>>x[i];
		}
		for(int i=1;i<n;i++){
			if(x[i+1]-x[i]<=d){
				if(n%2==0)cout<<"1";
					else cout<<"2";

			}
			else{
				cout<<"0";
				continue;
			}
		}

	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
