#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	bool flag=0;
	long long yi=0;
	cin>>a>>b>>c>>d;
	long long l=max(a.size(),b.size());
	for(int i=0;i<l;i++){
		if(a[i]!=c[i]){
			flag=1;
		}
	}
	if(flag==0) yi++;
	else{
		cout<<"0000";
		return 0;
	}
	flag=0;
	for(int i=0;i<2;i++){
		if(b[i]!=d[i]) flag=1;
	}
	if(flag==0)yi++;
	else{
		cout<<"1000";
		return 0;
	}
	flag=0;
	if(((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))||(b[2]=='D'||b[2]=='E')&&(d[2]=='D'||d[2]=='E')){
		yi++;
	}
	else{
		cout<<"1100";
		return 0;
	}
	if(b[2]+1==d[2]&&b[2]!='C'||b[2]-1==d[2]&&b[2]!='D')yi++;
	else{
		cout<<"1110";
		return 0;
	}
	for(int i=1;i<=yi;i++){
		cout<<"1";
	}
	return 0;
} 
