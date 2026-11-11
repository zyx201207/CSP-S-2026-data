#include <bits/stdc++.h>
using namespace std;
long long x[100000000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	for(int i=0;i<t;i+=1){
		int n,d;cin>>n>>d;
		int q=0;
		for(int j=0;j<n;j++){
			cin>>x[j];
		}
		for(int j=0;j<n-3;j++) {
			if(x[j+1]-x[j]<=d){
				if(x[j+2]-x[j+1]<=d){
					if(x[j+3]-x[j+2]<=d){
						if(x[j+1]-x[j]==x[j+3]-x[j+2]){
							q+=1;
						}
					}
				}
			}
			
		}
		cout<<q<<endl;
	}
	return 0;
}
