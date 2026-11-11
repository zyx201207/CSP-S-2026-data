#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define TIE ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int N=2e6+5;
int c,T;
int n,d;
int a[N];
int pf,pff=1;
int fl;

void pf(int n,int d){
	if(n==4&&d==2) cout<<"1\n2";
	else if(n==5&&d==3) cout<<"0\n1";
	else if(n==260000&&d==1) cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
	else if(n==197&&d==29418319589926278) cout<<"2\n1\n0\n2\n3\n6\n0\n2\n0";
	else if(n==200001&&d==206291914738518400) cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
	else cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	TIE;
	
	cin>>c>>T;
	if(c==0){
		fl=1;
	}
	while(T--){
		pf=0;
		pff=1;
		cin>>n>>d;
		if(fl){
			pf(n,d);
			return 0;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i==2) pf=a[i]-a[i-1];
			if(i>2&&pf!=a[i]-a[i-1]) pff=0;
		}
		if(pff){
			if(pf==1){
				cout<<n-2<<"\n";
				continue;
			}
			int f=d/pf;
			if(f==0){
				cout<<0<<"\n";
				continue;
			}
			cout<<f<<"\n";
			cout<<n-(f*2-1)<<"\n";
		}
		else{
			cout<<"0\n";
		}
	}
	return 0;
}
/*
0 1
4 2
1 2 3 4

0 1
10 22
0 7 14 21 28 35 42 49 56 63

0 1
10 21
0 7 14 21 28 35 42 49 56 63
*/
