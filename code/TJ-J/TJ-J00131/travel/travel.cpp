#include<bits/stdc++.h>
using namespace std;
string s1,s2,a,b;
char c,d;
int c1,c2,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	c=s1[2]; 
	d=s2[2];
	if(c1==c2&&c1!=1&&c2!=1&&c1!=16&&c2!=16){
		ans+=1000;
	}
	for(int i=0;i<2;i++){
		a+=s1[i];
		b+=s2[i];
	}
	if(a==b&&c1!=1&&c2!=1&&c1!=16&&c2!=16){
		ans+=100;
	}
	if(a==b&&c1!=1&&c2!=1&&c1!=16&&c2!=16&&a==b&&c=='A'&&d=='B'||a==b&&c=='A'&&d=='C'||a==b&&c=='B'&&d=='A'||a==b&&c=='B'&&d=='C'||a==b&&c=='C'&&d=='A'||a==b&&c=='C'&&d=='B'||a==b&&c=='F'&&d=='D'||a==b&&c=='D'&&d=='F'){
		ans+=10;
	}
	if(a==b&&c1!=1&&c2!=1&&c1!=16&&c2!=16&&c+1==d||c-1==d&&c+1!='D'&&c-1!='D'){
		ans+=1;
	}
	if(ans>=1000){
		cout<<ans;
	}
	else if(ans>=100&&ans<1000){
		cout<<0<<ans;
	}
	else if(ans>=10&&ans<100){
		cout<<00<<ans;
	}
	else if(ans>=1&&ans<10){
		cout<<000<<ans;
		
	}
	else if(ans==0){
		cout<<"0000";
		
	}
	return 0;
} 
