#include<bits/stdc++.h>
using namespace std;
string c11,c22,s11,s22,a11,a22;
char sa1,sa2;
int jue(int x){
	if(x>=0) return x;
	else return -x;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c11>>s11>>c22>>s22;
	if(c11==c22){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<s11.size();i++){
		if(s11[i]>='A'&&s11[i]<='F'){
			sa1=s11[i];
		}
		if(s11[i]>='0'&&s11[i]<='9'){
			a11+=s11[i];
		}
	}
	for(int i=0;i<s22.size();i++){
		if(s22[i]>='A'&&s22[i]<='F'){
			sa2=s22[i];
		}
		if(s22[i]>='0'&&s22[i]<='9'){
			a22+=s22[i];
		}
	}
	if(a11==a22){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(sa1<='C'&&sa2<='C'){
		cout<<1;
	}else if(sa1>='D'&&sa2>='D'){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(jue(int(sa2-sa1))==1&&sa1!='D'&&sa2!='D'&&sa1!='F'&&sa2!='F'){
		cout<<1;
	}else if(sa1=='D'&&sa2=='F'||sa1=='F'&&sa2=='D'){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
