#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int c,T,n;
long long a[2000006],m;
long long cha[2000006],sum;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0) ;
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			cha[i-1]=a[i]-a[i-1];
		}
		if(m<cha[1]||m>cha[1])cout<<0<<endl;
		else cout<<m-3<<endl;
	}
	return 0;
}
/*
0p
i am sad
ccf rp++ rp-- 
luogu User jfyjfy

*/
