#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e6+10;
int c,t,n;
LL d,x[N],l;
bool b=true;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		b=true;
		for(int i=1;i<=n;i++)cin>>x[i];
		sort(x+1,x+n+1);
		for(int i=2;i<n;i++)
			if(2*x[i]!=x[i-1]+x[i+1])b=false;
		l=x[2]-x[1];
		if(x[n]-x[1]<d*2||d<2*l){
			cout<<0<<"\n";
			continue;
		}
		if(b){
			LL t=d/l;
			cout<<n-t*2+1<<"\n";
		}
		else cout<<0<<"\n";
	}
	return 0;
}
