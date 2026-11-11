#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char s1[100],s2[100];
	int a[100],b[100];
	int c1,c2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}int flag=1; 
	for(int i=0;i<2;i++){
		a[i]=s1[i]-'0';
		b[i]=s2[i]-'0';
		if(a[i]!=b[i])
		flag=0;
	}
	if(flag){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}char c,d;
	c=s1[2];
	d=s2[2];
	if(c=='A'||c=='B'||c=='C'){
		if(d=='A'||d=='B'||d=='C'&&d!='D'){
			cout<<1;
		}
	}else if(c=='D'||c=='F'){
		if(d=='D'||d=='F'&&d!='C'){
			cout<<1;
		}
	}
	if(c=='A'||c=='B'||c=='C'){
		if(d=='D'||d=='F'){
			cout<<0<<0;
			return 0;
		}
	}
	if(c=='A'&&d=='B') {cout<<1;return 0;}
	else if(c=='B'&&(d=='A'||d=='C')){cout<<1;return 0;}
	else if(c=='C'&&d=='B') {cout<<1;return 0;}
	else if(c=='D'&&d=='F') {cout<<1;return 0;}
	else if(c=='F'&&d=='D') {cout<<1;return 0;}
	else{cout<<0;}
	
	return 0;
} 
