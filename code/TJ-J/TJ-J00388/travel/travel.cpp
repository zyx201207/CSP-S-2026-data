#include<bits/stdc++.h>
using namespace std;
int const MX=1e5+1;
char c1[MX],c2[MX],s1[MX],s2[MX];
int a,b,c;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	if(c1[0]==s1[0]&&c1[1]==s1[1]){
		cout<<1;
		a=1;
	}else{
		a=0;
		cout<<0;
	}
	int tmp=0;
	for(int i=0;i<=1;i++){
		if(c2[i]==s2[i]){
			tmp++;
		}
	}
	if(tmp==2&&a==1){
		cout<<1;
		b=1;
	}else{
		cout<<0;
		b=0;
	}
	if(c2[2]!=s2[2]&&a==1&&b==1&&(((65<=c2[2]&&c2[2]<=67)&&(65<=s2[2]&&s2[2]<=67))||((69<=c2[2]&&c2[2]<=70)&&(69<=s2[2]&&s2[2]<=70)))){
		cout<<1;
		c=1;
	}else{
		cout<<0;
		c=0;
	}
	if(a==1&&b==1&c==1&&abs(int(c2[2])-int(s2[2]))==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
