#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	bool a1,a2,a3,a4;
	if(a==c) a1=1;
	else a1=0;
	if(a1==1){
		if(b[0]==d[0]){
			if(b[1]==d[1]) a2=1;
			else a2=0;
		}
	}else a2=0;
	
	if(a2==1){
		if(((b[2]>='A'&&b[2]<='C')&&(d[2]>='A'&&d[2]<='C'))||((b[2]>='D'&&b[2]<='F')&&(d[2]>='D'&&d[2]<='F'))) a3=1;
		else a3=0;
	}else a3=0;
	if(a3==1){
		if(b[2]-d[2]==1 || d[2]-b[2]==1) a4=1;
		else a4=0;
	}else a4=0;
	cout<<a1<<a2<<a3<<a4;
	return 0;
}

