#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else{
		cout<<'1';
	}
	if(s1.substr(0,2)!=s2.substr(0,2)){
		cout<<"000";
		return 0;
	}else{
		cout<<'1';
	}
	int u=s1[2]-'A',v=s2[2]-'A';
	if(u>v){
		swap(u,v);
	}
	if(u/3!=v/3){
		cout<<"00";
		return 0;
	}else{
		cout<<'1';
	}
	if(u==3){
		u=4;
	}
	cout<<(u+1==v);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
