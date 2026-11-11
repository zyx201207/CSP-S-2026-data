#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3) {
		cout<<1;
		string t1=s2.substr(0,2),t2=s4.substr(0,2);
		if(t1==t2) {
			cout<<1;
			char c1=s2[2],c2=s4[2],c3=s4[2],c4=s2[2];
			int i1=int(c1-'A'),i2=int(c2-'A');
			if((c1=='A'&&c2=='D')||(c1=='A'&&c2=='F')||(c1=='B'&&c2=='D')||(c1=='B'&&c2=='F')||(c1=='C'&&c2=='D')||(c1=='C'&&c2=='F')||(c3=='A'&&c4=='D')||(c3=='A'&&c4=='F')||(c3=='B'&&c4=='D')||(c3=='B'&&c4=='F')||(c3=='C'&&c4=='D')||(c3=='C'&&c4=='F')) {
				cout<<"00";
			} else {
				cout<<1;
				if((abs(i1-i2))!=1||(c1=='C'&&c2=='D')||(c1=='D'&&c2=='C')) {
					cout<<0;
				} else {
					cout<<1;
				}
			}
		} else {
			cout<<"000";
		}
	} else {
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
