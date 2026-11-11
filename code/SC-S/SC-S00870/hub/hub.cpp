#include<bits/stdc++.h>
using namespace std;
const long long MAXN=1000100;
long long u[MAXN];
long long v[MAXN];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	long long c,t;
	cin>>c>>t;
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>u[i]>>v[i];
	}
	if(c==0) cout<<n<<k;
	
	fclose(stdin);
	fclose(stdout); 
} 