#include<bits/stdc++.h>
using namespace std;
const int N=2e6+6;
#define int long long 
int n,d,a[N],cnt;
void s1(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=2){
		cout<<0<<"\n";
		return; 
	}
	int t=a[2]-a[1];
	t=d/t;
	if(t<=1){
		cout<<0<<"\n";
		return; 
	}
	cnt=0;
	for(int i=1;i<=n;i++){
		if(i+2*t-1<=n) cnt++;
	}
	cout<<cnt<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		s1();
		
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
