#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int l1=s1[2]-'A'+1;
	int l2=s2[2]-'A'+1;								
	bool f1,f2,f3,f4;
	if(c1==c2){
		f1=true;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			f2=true;
			if(l1<=3&&l2<=3||l1>3&&l2>3){
				f3=true;
				if(l1-l2==1||l2-l1==1){
					f4=true;
				}else{
					f4=false;
				}
			}else{
				f3=false;
			}
		}else{
			f2=false;
		}
	}else{
		f1=false;
	}
	if(f1){
		cout<<"1";
		if(f2){
			cout<<"1";
			if(f3){
				cout<<"1";
				if(f4){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
