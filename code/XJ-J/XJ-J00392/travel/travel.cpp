#include<bits/stdc++.h>
using namespace std;
int a,b,z1,z2,f=0,af=0,bf=0,cc,dd;
char c[15],d[15];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	if(a==b){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(a==b&&c[0]==d[0]&&c[1]==d[1]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(a==b&&c[0]==d[0]&&c[1]==d[1]){
		if(int(c[2])==68||int(c[2])==69){
			af=1;
		}
		if(int(d[2])==68||int(d[2])==69){
			bf=1;
		}
	}
	if(a==b&&c[0]==d[0]&&c[1]==d[1]&&bf==af){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(bf==af&&a==b&&c[0]==d[0]&&c[1]==d[1]){
		if(int(c[2])==int(d[2])||int(c[2])==int(d[2])+1||int(c[2])==int(d[2])-1){
			cc=int(c[0])*10+int(c[1]);
			dd=int(d[0])*10+int(d[1]);
			if(cc==dd||cc==dd+1||cc==dd-1){
				f=1;
			}
		}	
	}
	
	if(f==1){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}