#include <bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,s1;
	string a2,s2;
	cin>>a1>>a2>>s1>>s2;
	if(a1==s1){
		a[1]=1;
		cout<<1;
	}else{
		a[1]=0;
		cout<<0;
	}
	if(a[1]==1){
		if(int(a2[0]+'0')==int(s2[0]+'0')&&int(a2[1]+'0')==int(s2[1]+'0')){
			cout<<1;
			a[2]=1;
		}else{
			cout<<0;
			a[2]=0;
		}
	}else{
		cout<<0;
		a[2]=0;
	}
	if(a[2]==1){
		if(a2[2]=='A'||a2[2]=='B'||a2[2]=='C'&&s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
			a[3]=1;
			cout<<1;
		}else if(a2[2]=='D'||a2[2]=='F'&&s2[2]=='D'||s2[2]=='F'){
			a[3]=1;
			cout<<1;
		}else{
			a[3]=0;
			cout<<0;
		}
	}else{
		a[3]=0;
		cout<<0;
	}
	if(a[3]==1){
		if((a2[2]-s2[3]==char(1)||s2[2]-a2[2]==char(1))||(a2[2]=='D'||a2[2]=='F'&&s2[2]=='D'||s2[2]=='F')){
			if(a2[2]=='A'||a2[2]=='B'||a2[2]=='C'&&s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
				a[4]=1;
				cout<<1;
			}else if(a2[2]=='D'||a2[2]=='F'&&s2[2]=='D'||s2[2]=='F'){
				a[4]=1;
				cout<<1;
			}else{
				cout<<0;
				a[4]=0;
			}
		}else{
			cout<<0;
			a[4]=0;
		}
	}else{
		a[4]=0;
		cout<<0;
	}
	return 0;
}  
