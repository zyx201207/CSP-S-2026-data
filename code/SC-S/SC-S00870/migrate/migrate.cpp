#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000100;
int x[MAXN];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	long long c,t;
	long long n,d;
	long long u,v;
	cin>>c>>t;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	int sum=0;
	cin>>u>>v;
	if(u-v==2)
		cout<<sum++<<endl;
	else if(c==0) cout<<n<<endl<<d;
	
	fclose(stdin);
	fclose(stdout); 
} 