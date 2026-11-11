#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string a1,b1,a2,b2;
	cin>>a1>>a2>>b1>>b2;
	int len1=a2.size()-1;
	int len2=b2.size()-1;
	if(a1==b1){
		cout<<"1";
		bool ok=true;
		for(int i=0;i<len1;i++){
			if(a2[i]!=b2[i]){
				ok=false;
			}
		}
		if(ok){
			cout<<"1";

			if(a2[len1]>='A'&&a2[len1]<='C'&&b2[len2]>='A'&&b2[len2]<='C'||a2[len1]>='D'&&a2[len1]<='F'&&b2[len2]>='D'&&b2[len2]<='F'){
				cout<<"1";
				int aa=a2[len1]-'0';
				int bb=b2[len2]-'0';
				if(abs(aa-bb)==1){
					cout<<"1";
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
