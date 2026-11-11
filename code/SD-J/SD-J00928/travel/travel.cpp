#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,c1,c2;
	cin>>s1>>s2>>c1>>c2;
	int a=0,b=0,c=0,d=0,cnt=0;
	if(c1==s1){
		cout<<1;
		cnt++;
		string s=s2.substr(0,2),c=c2.substr(0,2);
		if(s==c){
			cout<<1;
			cnt++;
			if((s2[2]<='C'&&c2[2]<='C')||(s2[2]>='D'&&c2[2]>='D')){
				cout<<1;
				cnt++;
				char ss=s2[2],cc=c2[2];
				if(abs(int(ss)-int(cc))==1&&(ss!='C'||cc!='D')&&(ss!='D'||cc!='C')){
					cout<<1;
					cnt++;
				}
			}
		}
	}
	for(int i=1;i<=4-cnt;i++) cout<<0;
	return 0;
}
