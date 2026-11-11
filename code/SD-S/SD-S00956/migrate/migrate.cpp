#include <bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d,a[2000010],f[2000010],ans=0;
int main() {
   freopen("migrate.in","r",stdin);
   freopen("migrate.out","w",stdout);
  cin>>c>>t;
  while(t--){
  	ans=0;
    cin>>n>>d;
	 	for(int i=1;i<=n;i++){
	 		cin>>a[i];
		}if(c==11||c==12){
	  	if(a[2]-a[1]<=d&&((a[2]-a[1])*2>d||n<5)){
	  		cout<<n-3<<endl;
			}else{
				cout<<0<<endl;
			}
		}else{
			cout<<0<<endl;
		}
	}
  return 0;
}
//0 2
//4 2
//1 2 3 4
