#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	bool v=1;
	for(int i=0;i<2;i++){
		if(a[i]!=c[i]){
			v=0;
		}
	}
	if(v){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<2;i++){
		if(b[i]!=d[i]){
			v=0;
		}
	}
	if(v){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	int x=b[2]-'A',y=d[2]-'A';
	if(x>y) swap(x,y);
	if(0<=x&&x<=2&&y>2){
		cout<<"00";
		return 0;
	}else{
		cout<<"1";
	}
	if(y-x==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}