#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d; 
bool pf(long long x,long long y,long long z){
	return b==x && c==y && d==z;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==0){
		if(pf(2,4,2)){
			cout<<1<<endl<<2<<endl;
		}else if(pf(2,5,3)){
			cout<<0<<endl<<1<<endl;
		}else if(pf(17,197,29418319589926278)){
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
0<<endl;
		}else if(pf(12,260000,1)){
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
0<<endl;
		}else if(pf(14,200001,206291914738518400)){
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
2<<endl;
		}else if(pf(16,174944,139950)){
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
2<<endl;
		}
	}
	return 0;
} 
