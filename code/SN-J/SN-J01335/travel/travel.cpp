#include<bits/stdc++.h>
#define ll long long
using namespace std;

string c1,s1,c2,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>c1>>s1>>c2>>s2;
	bool flag=1;
	for(int i=0;i<2;i++){
		if(c1[i]!=c2[i]){
			flag=0;
		}
	}
	if(flag==0){
		cout << "0000";
		return 0;
	} 
	bool flag1=1;
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			flag1=0;
		}
	}
	if(flag1==0){
		cout<<"1000";
		return 0;
	}
	char a1=s1[2],a2=s2[2];
	if(!((a1<='C'&&a2<='C')||(a1>='D'&&a2>='D'))){
		cout<<"1100";
		return 0;
	}
	if(a1=='C'&&a2=='A'||a2=='C'&&a1=='A'){
		cout << "1110";
	}
	else cout<<"1111";
	return 0;
}

