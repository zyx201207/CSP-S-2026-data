#include<bits/stdc++.h>
using namespace std;

string s1,c1,s2,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) cout<<"0000";
	else{
		cout<<"1";
		bool f=0;
		for(int i=0;i<2;i++){
			if(s1[i]!=s2[i]){
				f=1;
				break;
			}
		}	
		if(f==0){
			cout<<"1";
			if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='D'&&s2[2]<='F'||s2[2]>='A'&&s2[2]<='C'&&s1[2]>='D'&&s1[2]<='F'){
				cout<<"00";
			}else{
				cout<<"1";
				if(s1[2]+1==s2[2]||s2[2]+1==s1[2]){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}
		}
		else cout<<"000";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

