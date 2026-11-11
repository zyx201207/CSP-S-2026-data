#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2){
		ans+='1';
	}else{
		ans+='0';
	}
	int f=0;
	for(int i=0;i<2;++i){
		if(s1[i]!=s2[i]){
			ans+='0';
			f=1;
			break;
		}
	}
	if(f==0){
		ans+='1';
	}
	int t=1;
	if(f==0 && ((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'))){
		ans+='1';
		t=0;
	}else{
		ans+='0';
	}
	if(t==0&&abs(s1[2]-s2[2])==1){
		ans+='1';
	}else{
		ans+='0';
	}
	cout << ans;
	return 0;
}
