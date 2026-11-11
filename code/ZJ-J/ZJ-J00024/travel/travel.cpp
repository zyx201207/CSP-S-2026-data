#include<bits/stdc++.h>
using namespace std;
int main(){
	// freopen("E:\\cspj\\down\\travel\\travel5.in","r",stdin);
	// freopen("E:\\cspj\\down\\travel\\travel5.out","w",stdout);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	if((s1[2]<='C')!=(s2[2]<='C')){
		cout<<"00";
		return 0;
	}
	cout<<"1";
	int id[10]={1,2,3,4,-1,5};
	if(abs(id[s1[2]-'A']-id[s2[2]-'A'])!=1){
		cout<<"0";
		return 0;
	}
	cout<<"1";
	return 0;
}