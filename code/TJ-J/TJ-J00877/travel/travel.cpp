#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000"<<endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	a=s1[0];
	b=s2[0];
	a+=s1[1];
	b+=s2[1];
	if(a!=b){
		cout<<"1000"<<endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(!('A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C'||'D'<=s1[2]&&s1[2]<='E'&&'D'<=s2[2]&&s2[2]<='E')){
		cout<<"1100"<<endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(abs(s1[2]-s2[2])!=1){
		cout<<"1110"<<endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	cout<<"1111"<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
