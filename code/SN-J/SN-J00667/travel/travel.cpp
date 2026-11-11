//赵晗羽 西安辅轮中学  SN-J00667 
#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
		return 0;
	}else if(b[0]!=d[0]||b[1]!=d[1]){
		cout<<"1000";
		return 0;	
	}else{
		string t="";
		t+=b[2];
		t+=d[2];
		if(t=="AB"||t=="BA"||t=="BC"||t=="CB"||t=="DF"||t=="FD"){
			cout<<"1111";
			return 0;
		}else if(t=="AC"||t=="CA"){
			cout<<"1110";
		}else cout<<"1100";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
