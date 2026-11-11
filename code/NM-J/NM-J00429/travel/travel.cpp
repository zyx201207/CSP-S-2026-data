#include<bits/stdc++.h>
using namespace std;
bool flg(string &s1,string &s2) {
	if(s1[0]==s2[0]&&s1[1]==s2[1]) {
		return true;
	} else {
		return false;
	}
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
//	cout<<c1<<" "<<s1<<" "<<c2<<" "<<s2;
	bool allf=true;
	if(c1==c2) {
		printf("%d",1);
		allf=false;
	} else {
		printf("%d",0);
		allf=true;
	}
	if(!allf) {
		bool f=true;
		bool flag=true;
		if(flg(s1,s2)) {
			printf("%d",1);
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C') {
				if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') {
					printf("%d",1);
					f=false;
				}
			} else if(s1[2]=='D'||s2[2]=='F') {
				if(s2[2]=='D'||s2[2]=='F') {
					printf("%d",1);
					f=false;
				}
			}
			if(!f) {
				if(s1[2]+1==s2[2]||s1[2]-1==s2[2]) {
					printf("%d",1);
					flag=false;
				} else if(s2[2]=='D'&&s1[2]=='F') {
					
					printf("%d",1);
					flag=false;
				}else if(s2[2]=='F'&&s1[2]=='D'){
					printf("%d",1);
					flag=false;
				}
			}

		}else{
			printf("%d",0);
		}
		if(f) {
			printf("%s","0");
		}
		if(flag) {
			printf("%d",0);
		}
	}else{
		printf("%s","000");
	}


	return 0;
}
