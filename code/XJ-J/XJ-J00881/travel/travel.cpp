#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}else{
		cout<<1;
		if(s1[0]!=s2[0]){
			cout<<"00";
		}else if(s1[1]!=s2[1]){
			cout<<"00";
		}else{
			cout<<1;
			if(s1[2]=='C'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='C'){
				cout<<0;
			}else if(s1[2]=='A'||'B'||'C'&&s2[2]=='A'||'B'||'C'||s1[2]=='D'||'F'&&s2[3]=='D'||'F'){
				cout<<1;
			}else{
				cout<<0;
			}
		if(s1[2]-s2[2]==0||s1[2]-s2[2]==-1){
			cout<<1;
		}
		else{
			cout<<0;
		}	
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}