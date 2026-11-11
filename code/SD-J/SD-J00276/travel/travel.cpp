#include<bits/stdc++.h>
using namespace std;
long long c1,c2;
string s1,s2;
bool cmp(string a,string b){
	bool aa=0,bb=0;
	for(long long i=0;i<3;i++){
		if(a[2]=='A'+i){
			aa=1;
		}
		if(b[2]=='A'+i){
			bb=1;
		}
	}
	if(aa==bb){
		return 1;
	}
	else{
		return 0;
	}
}
bool cmpp(string a,string b){
	bool aa=0,bb=0;
	for(long long i=0;i<3;i++){
		if(a[2]=='A'+i){
			aa=1;
		}
		if(b[2]=='A'+i){
			bb=1;
		}
	}
	if(aa==0 && bb==0){
		return 1;
	}
	else if(aa==1 && bb==1){
		long long aaa=int(a[2]);
		long long bbb=int(b[2]);
		if(abs(aaa-bbb)==1){
			return 1;
		}
		else{
			return 0;
		}
	}
	else{
		return 0;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			cout<<1;
			if(cmp(s1,s2)){
				cout<<1;
				if(cmpp(s1,s2)){
					cout<<1;
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}

