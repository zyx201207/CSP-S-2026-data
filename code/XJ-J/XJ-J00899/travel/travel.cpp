#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans,a;
int c;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	a='1';
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans='1';
	}else{
		ans=ans+'0'+'0'+'0'+'0';
		cout<<ans;
		return 0;
	}
	for(int i=0;i<=1;i++){
		if(s1[i]==s2[i] && i==0){
			c=2;
			continue;
		}
		if(s1[i]==s2[i] && c==2){
			ans=ans+'1';
			c=0;
		}
	}
	if(ans==a){
		ans=ans+'0'+'0'+'0';
		cout<<ans;
		return 0;
	}
	if(s1[2]>='A' && s1[2]<='C' && s2[2]>='A' && s2[2]<='C'){
		ans=ans+'1';
		if(s1[2]-s2[2]==1 || s2[2]-s1[2]==1){
		ans=ans+'1';
	}else{
		ans=ans+'0';
	}
	}else if(s1[2]>='D' && s1[2]<='F' && s1[2]>='D' && s2[2]<='F'){
		if(s1[2]-s2[2]==1 || s2[2]-s1[2]==1){
		ans=ans+'1';
	}else{
		ans=ans+'0';
	}
	}else{
		ans=ans+'0'+'0';
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}