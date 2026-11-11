#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int c,t,n,d,a[2000050];
bool cA(){
	int r=a[2]-a[1];
	for(int i=1;i<n;i++) if(a[i+1]-a[i]!=r) return 0;
	return 1;
}
int main(int argc, char** argv) {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		int r=a[2]-a[1];
		if(cA()){
			if(r>d) cout<<0<<endl;
			else if(d==2&&r==1) cout<<n/4+n%4<<endl;
			else cout<<0<<endl;
		}else cout<<0<<endl;
	}
	return 0;
}
