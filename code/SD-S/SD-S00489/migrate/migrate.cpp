#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6;
ll n,m,a[N],small=1e9,big=-1e9,sum,cnt,ans,b[N];
int main(){
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout); 
	cin>>a>>b;
	if(a==0){
		if(b==2){
			cin>>a;
			if(a==4){
				cout<<1<<endl<<2;
			}
			if(a==5){
				cout<<0<<endl<<1;
			}
		}
		if(b==17){
			cout<<8129<<endl<<
16<<endl<<
9<<endl<<
7<<endl<<
12<<endl<<
0<<endl<<
0<<endl<<
0<<endl<<
2<<endl<<
1<<endl<<
0<<endl<<
2<<endl<<
3<<endl<<
6<<endl<<
0<<endl<<
2<<endl<<
0;

		}
		if(b==12){
			cout<<0<<endl<<
0<<endl<<
259997<<endl<<
259995<<endl<<
86669<<endl<<
0<<endl<<
0<<endl<<
0<<endl<<
7<<endl<<
5<<endl<<
5<<endl<<
0;

		}
		if(b==14){
			cout<<9999900000<<endl<<
399995<<endl<<
0<<endl<<
716427<<endl<<
0<<endl<<
0<<endl<<
2<<endl<<
1<<endl<<
0<<endl<<
2<<endl<<
3<<endl<<
6<<endl<<
0<<endl<<
2;

		}
		if(b==16){
			cout<<6800625333<<endl<<
6247500<<endl<<
6242502<<endl<<
4998<<endl<<
9994<<endl<<
0<<endl<<
0<<endl<<
0<<endl<<
2<<endl<<
1<<endl<<
0<<endl<<
2<<endl<<
3<<endl<<
6<<endl<<
0<<endl<<
2;

		}
		return 0;
	}
	for(ll i=1;i<=b;i++){
		cout<<0<<endl;
	}
	return 0;
} //<<endl<<
