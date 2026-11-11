#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int ans[4]={-1,-1,-1,-1};
bool check(string x,string y){
	string p=x.substr(0,2),q=y.substr(0,2);
	if(p==q)return 1;
	else return 0;
}
bool checkk(string x,string y){
	char u=x[2],v=y[2];
	if(u=='A'||u=='B'||u=='C'){
		if(v=='A'||v=='B'||v=='C'){
			return 1;
		}
	}
	if(u=='D'||u=='E'){
		if(v=='D'||v=='E'){
			return 1;
		}
	}
	return 0;
}
bool checck(string x,string y){
	char u=x[2],v=y[2];
	if(u=='A'){
		if(v=='B'){
			return 1;
		}
	}
	if(u=='B'){
		if(v=='C'){
			return 1;
		}
	}
	if(u=='C'){
		if(v=='B'){
			return 1;
		}
	}
	if(u=='D'){
		if(v=='E'){
			return 1;
		}
	}
	if(u=='E'){
		if(v=='D'){
			return 1;
		}
	}
	else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c==cc){
		ans[0]=1;
		if(check(s,ss)){
			ans[1]=1;
			if(checkk(s,ss)){
				ans[2]=1;
				if(checck(s,ss)){
					ans[3]=1;
				}
			}	
		}
	}
	for(int i=0;i<4;i++){
		if(ans[i]!=-1)cout<<ans[i];
		else cout<<0;
	}
	return 0;
}
