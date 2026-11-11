#include<bits/stdc++.h>
using namespace std;
string s1,s2;
string c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>c1>>c2;
	if(s1==c1){
		cout<<"1";
		for(int i=0;i<2;i++){
			if(c2[i]!=s2[i]){
				cout<<"000";
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
		}
		cout<<"1";
		if(c2[2]=='D' && s2[2]=='F'
		|| c2[2]=='F' && s2[2]=='D'){
			cout<<"11";
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
		if(c2[2]=='D' || c2[2]=='F' 
		|| s2[2]=='F' || s2[2]=='D'){
			cout<<"00";
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
		cout<<"1";
		if(abs(c2[2]-s2[2])==1) cout<<"1";
		else cout<<"0";
	}else{
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
