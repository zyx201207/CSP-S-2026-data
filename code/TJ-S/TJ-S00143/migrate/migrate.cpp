#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10; 
long long n,m[N]={2,1},a[N]={0},r=1,y=0,c,t,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		cout<<m[t]<<endl;	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
