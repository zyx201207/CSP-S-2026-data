#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}else{
		cout<<"1";
		if(s1.substr(0,2)==s2.substr(0,2)){
			cout<<"1";
			char a1=s1[2],a2=s2[2];
			if(a1>a2)swap(a1,a2);
			if(a2<='C'){
				cout<<"1";
				if((a1=='A'&&a2=='B')||(a1=='B'&&a2=='C'))cout<<"1";
				else cout<<"0";
			}else if(a1>='D'){
				cout<<"1";
				if(a1=='D'&&a2=='F')cout<<"1";
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
