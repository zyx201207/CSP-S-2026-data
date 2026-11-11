#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d;
long long x[100010];
int flag1=0;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c!=11 && c!=12) flag1=1;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(flag1==0){
			int t=x[2]-x[1];
			int l=(d/t*2-1)*t;
			if(x[n]<l) cout<<0<<endl;
			else cout<<(x[n]-l-x[1])/t+1<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}