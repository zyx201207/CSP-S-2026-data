#include<bits/stdc++.h>
using namespace std;
char a1,a2;
int c1,s1,c2,s2,v[1000];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c1>>s1>>a1>>c2>>s2>>a2;
	v[(int)'A']=1;
	v[(int)'B']=1;
	v[(int)'C']=1;
	v[(int)'D']=2;
	v[(int)'E']=2;
	if(c1==c2)cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(s1==s2)cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if(v[(int)a1]==v[(int)a2]){
		cout<<"1";
		if(v[(int)a1]==2){
			cout<<"1";
			return 0;
		}else{
			if((int)a1>(int)a2)swap(a1,a2);
			if(a1=='A'&&a2=='B'){
				cout<<"1";
				return 0;
			}
			if(a1=='B'&&a2=='C'){
				cout<<"1";
				return 0;
			}
		}
		cout<<"0";
	}
	else{
		cout<<"00";
	}
	return 0;
}
