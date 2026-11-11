#include<bits/stdc++.h>
using namespace std;
string r1,r2,x1,x2;
bool f1,f2,f3,f4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>r2>>x1>>x2;
	if(r1==x1){
		f1=1;
	}
	char n=r2[0],n1=r2[1];
	char m=x2[0],m1=x2[1];
	if(n==m && n1==m1 && f1==1){
		f2=1;
	}
	char L=r2[2],K=x2[2];
	if(f1==1 && f2==1&&((L<='C' && L>='A' && K<='C' && K>='A') || (L>='D' && L<='F' && K>='D' && K<='F'))){
		f3=1;
	}
	if(f3==1&&((L<='C' && L>='A' && K<='C' && K>='A') || (L>='D' && L<='F' && K>='D' && K<='F')))
		if(L-1==K || K-1==L || L+1==K || K+1==L ){
			f4=1;
		}
	cout<<f1<<f2<<f3<<f4;
	return 0;
} 
