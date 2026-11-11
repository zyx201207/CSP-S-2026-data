#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6;
int n,d;
int a[N];
void solveA(){
	int re=abs(a[2]-a[1]);
	int maximum=abs(a[n]-a[1]);
	int aby=d/re;
	aby++;
	if(re>d||maximum<=re)cout<<0;
	else{
		int ans=0;
		cout<<n-2;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		bool A=1;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=2;i<n;i++)if((long long)(abs(a[i]-a[i-1]))!=(long long)(abs(a[i+1]-a[i])))A=0;
		if(A){
			solveA();
		}
		cout<<endl;
	}
	
	return 0;
}
