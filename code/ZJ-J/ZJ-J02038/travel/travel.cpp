#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",in);
	freopen("travel.out","w",out);
	int n,m,x;
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	for(int i=0;i<3;i++){
		if(a[i]==c[i]) n=0;
		else n=1;
	}
	if(n==0){
		cout<<"1"<<" ";
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<"1"<<" ";
			if(b[2]>='A'&&b[2]<='C') m=0;
			else m=1;
			if(b[2]>='A'&&d[2]<='C') x=0;
			else x=1;
			if(m=x){
				cout<<"1"<<" ";
				if(b[2]-d[2]==1||d[2]-b[2]==1) cout<<"1"<<" ";
				else cout<<"0"<<" ";
			}
			else cout<<"0"<<" ";
		}
		else cout<<"0"<<" ";
	}
	else cout<<"0"<<" ";
	return 0;
}