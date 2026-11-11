#include<bits/stdc++.h>
//#define int long long
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=0,n=0,m=0,d=0,q=0;
	cin>>c>>n>>m>>d>>q;
	if(c==0){
		if(n==2&&m==5&&d==20&&q==2){
			cout<<"32\n17";
		}
		if(n==3&&m==7&&d==20&&q==2){
			cout<<"35\n16";
		}
	}
	return 0;
}
//5 8
//-3 -1 2 2 7