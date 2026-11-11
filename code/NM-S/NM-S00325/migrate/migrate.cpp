#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	int c,t,w;
	int n,d;
	int x[100005];
	cin>>c>>t;
	int ans=0;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		for(int j=0;j<n;j++){
			cin>>x[j];
			if(x[i]>x[j]){
				if(x[i]-x[j]<=d){
				continue;
			}
			if(x[i]-x[j]>d){
				w=x[i]-x[j];
				if(w%d==0){
					continue;
				}
				if(w%d!=0){
					ans++;
				}
			}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
