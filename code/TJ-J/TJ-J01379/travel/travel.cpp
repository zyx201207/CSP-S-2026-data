#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool f=0;
	int c1,s1,sum=0;
	string c2,s2,ans=" ",cnt=" ";
	char num,jb;
	cin>>c1>>c2>>s1>>s2;
	for(int i=1;i<=c2.size();i++){
		if(c2[i]>='0'&&c2[i]<='9'){
			ans=c2[i];
		}
	}
	for(int i=1;i<=s2.size();i++){
		if(s2[i]>='0'&&s2[i]<='9'){
			cnt=s2[i];
		}
	}
	for(int i=1;i<=c2.size();i++){
		if(c2[i]>='A'&&c2[i]<='F'){
			num=c2[i];
		}
	}
	for(int i=1;i<=s2.size();i++){
		if(s2[i]>='A'&&s2[i]<='F'){
			jb=s2[i];
		}
	}
	if(c1==s1){
		cout<<"1";
		if(ans.size()==cnt.size()){
			for(int i=1;i<=ans.size();i++){
				if(ans[i]==cnt[i]){
					sum++;
				}
			}
			if(sum==ans.size()){
				cout<<"1";
				if(num=='A'){
					if(jb=='B'||jb=='C'){
						cout<<"1";
						f=1;
					}
				}
				else if(num=='B'){
					if(jb=='A'||jb=='C'){
						cout<<"1";
						f=1;
					}
				}
				else if(num=='C'){
					if(jb=='B'||jb=='A'){
						cout<<"1";
						f=1;
					}
				}
				else if(num=='D'&&jb=='F'){
					cout<<"1";
					f=1;
				}
				else if(num=='F'&&jb=='D'){
					cout<<"1";
					f=1;
				}
				else{
					cout<<"00";
				}
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	if(f==1){
		if(num!='C'&&num!='D'){
			if(char(num+1)==jb||char(num-1)==jb){
				cout<<"1";
			}
		}
		else if(num=='C'&&jb=='B'){
			cout<<"1";
		}
		else if(num=='D'&&jb=='F'){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	return 0;
}
