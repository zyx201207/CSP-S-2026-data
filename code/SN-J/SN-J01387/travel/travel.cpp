#include<bits/stdc++.h>
using namespace std;

int c1,c2;
string s1,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2)	cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	
	int a1=0,b1=0;
	for(int i=0;i<2;i++){
		a1+=s1[i];
		b1+=s2[i];
	}
	if(a1==b1)	cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	
	int a2=s1[2],b2=s2[2];
	if(a2<=67 && b2<=67){
		if(a2+1==b2 || a2-1==b2){
			cout<<11;
		}else{
			cout<<10;
		}
	}else if(a2>67 && b2>67){
		if(a2+1==b2 || a2-1==b2){
			cout<<11;
		}else{
			cout<<10;
		}
	}else{
		cout<<0<<0;
	}
	
	return 0;
}








