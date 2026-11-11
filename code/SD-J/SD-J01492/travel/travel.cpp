#include<bits/stdc++.h> 
using namespace std;
string ans="";
void f(){
	while(ans.size()!=4){
		ans+="0";
	}
	cout<<ans;
	return;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string c1,s1,c2,s2,a="0ABC0DF0",b="ABC";
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans+="1";
	}else{
		ans+="0";
		f();
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		ans+="1";
	}else{
		ans+="0";
		f();
		return 0;
	}
	int ok=1;
	for(int i=0;i<=2;i++){
		if(s2[2]==b[i])	ok++;
		if(s1[2]==b[i])	ok++;
	}
	if(ok==3){
		ans+="1";
	}else if(ok==1){
		ans+="1";
	}else{
		ans+="0";
		f();
		return 0;
	}
	ok=1;
	for(int i=1;i<=6;i++){
		if(s1[2]==a[i]&&(s2[2]==a[i-1]||s2[2]==a[i+1])){
			ans+="1";
			ok=0;
			break;
		}	
	}   
	if(ok)
		ans+="0"; 
	cout<<ans;                                                                                                                                      
	return 0;
}
