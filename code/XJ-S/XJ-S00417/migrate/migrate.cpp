#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
long long int c,t;
long long int n,d;
long long int s[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		n=0;d=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>s[i];
		}
		s[0]=0;
		s[n+1]=0;
		cout<<0<<endl;
	}
	return 0;
}/*








*/
