#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int x[N];
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	int n,d,ans=0;
	for(int k=1;k<=t;k++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		for(int i=1;i<=n;i++){
			if(x[i]-x[i-1]==x[i+1]-x[i]){
				ans++;
			}
		}
		if(ans==n-1){
			if(n%2==0){
				cout<<n/d-1<<endl;
			}else{
				cout<<n/d<<endl;
			}
		}
		ans=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
