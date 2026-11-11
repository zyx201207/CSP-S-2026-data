# include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	string p1,p2;
	p1=s1[0]+s1[1];
	p2=s2[0]+s2[1];
	if(p1==p2){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'){
		cout<<1;
	}else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'){
		cout<<"11";
		return 0;
	}else{
		cout<<"00";
		return 0;
	}
	int a=s1[2]-s2[2];
	if(a<0) a=-a;
	if(a==1) cout<<1;
	else cout<<0;
	
	
	return 0;
}
