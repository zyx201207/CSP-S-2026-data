#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int x1,x2,z1,z2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++){
		z1=z1*10+(s1[i]-48);
		z2=z2*10+(s2[i]-48);
	}
	char a1=s1[2],a2=s2[2];
	if(c1==c2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(z1==z2) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(((a1>='A'&&a1<='C')&&(a2>='A'&&a2<='C'))||((a1=='D'||a1=='F')&&(a2=='D'||a2=='F'))) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(a1<='C'&&a2<='C'){
		if(abs(a1-a2)==1) cout<<1;
		else cout<<0;
	}else if((a1=='C'||a1=='D')&&(a2=='C'||a2=='D')){
		cout<<0;
	}else{
		if((a1=='D'||a1=='F')&&(a2=='D'||a2=='F')) cout<<1;
		else cout<<0;
	}
	return 0;
}
