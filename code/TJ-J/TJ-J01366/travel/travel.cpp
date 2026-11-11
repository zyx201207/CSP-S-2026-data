#include<bits/stdc++.h>
using namespace std;
string ca="",sa="",cb="",sb="",t="";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>sa>>cb>>sb;
	if(ca==cb){
		t+='1';
		if(sa[0]==sb[0] && sa[1]==sb[1]){
			t+='1';
			if(sa[2]<'D' && sb[2]<'D' || sa[2]>='D' && sb[2]>='D'){
				t+='1';
				if(sa[2]+1==sb[2] || sa[2]-1==sb[2]){
					t+='1';
				}else{
					t+='0';
				}
			}else{
				t+="00";
			}
		}else{
			t+="000";
		}
	}else{
		t+="0000";
	}
	cout<<t;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
