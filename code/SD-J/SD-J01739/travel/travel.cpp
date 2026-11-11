#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char c[5]={'A','B','C','D','F'};
int h[5]={'A'+'C','A'+'B','D'+'F'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool ans1=0,ans2=0,ans3=0,ans4=0;
	if(c1==c2) ans1=1;
	else{
		cout<<"0000";
		return 0;
	}
	int R=0,X=0;
	char r,x;
	for(int i=0;i<s1.size();i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			R=R*10+(s1[i]-'0');
		}
		else r=s1[i];
	}
	for(int i=0;i<s2.size();i++){
		if(s2[i]>='0'&&s2[i]<='9'){
			X=X*10+(s2[i]-'0');
		}
		else x=s2[i];
	}
	if(R==X) ans2=1;
	else{
		cout<<"1000";
		return 0;
	}
	for(int i=0;i<3;i++){
		if(x+r==h[i]) ans3=1;
	}
	if(ans3==0){
		cout<<"1100";
		return 0;
	}
	for(int i=0;i<4;i++){
		if(x==c[i]&&r==c[i+1]||x==c[i+1]&&r==c[i]){
			ans4=1;
		}
	}
	if(ans4) cout<<"1111";
	else cout<<"1110";
	return 0;
} 
