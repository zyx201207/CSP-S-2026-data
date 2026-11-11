#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++){
		if(c1[i]!=c2[i]){
			cout<<"0000";
			return 0;
		}
	}
	cout<<'1';
	char a,b;
	for(int i=0;i<3;i++){
		if(i==2){
			a=s1[i],b=s2[i];
		}if(s1[i]!=s2[i]&&i!=2){
			cout<<"000";
			return 0;
		}
	}
	cout<<'1';
	if((a>='A'&&a<='C'&&b>='A'&&b<='C')||(a>='D'&&a<='F'&&b>='D'&&b<='F')){
		cout<<'1';
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(int(a)-int(b))==1){
		cout<<'1';
	}else cout<<'0';
	return 0;
} 
