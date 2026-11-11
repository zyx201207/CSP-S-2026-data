
#include<bits/stdc++.h>
using namespace std;
int main() {
	char c1[3]= {0},s1[3]= {0},c2[3]= {0},s2[3]= {0};

	int a[4]= {0};
	for(int i=1; i<=3; i++) {
		cin>>c1[i];
		cin>>s1[i];
		cin>>c2[i];
		cin>>s2[i];
	}
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	if(c1!=c2) {
		a[1]=0;
	} else {
		a[1]=1;
	}
	for(int i=1; i<=2; i++) {
		if(s1[i]==s2[i]) {
			a[2]=1;
			break;

		} else {
			a[2]=0;
			break;
		}

	}
	if((s1[3]=='A'&& s2[3]=='B')||(s1[3]=='B'&& s2[3]=='A')||(s1[3]=='B'&& s2[3]=='C')||(s1[3]=='C'&& s2[3]=='B')||(s1[3]=='D'&& s2[3]=='F')||(s1[3]=='F'&& s2[3]=='D')) {
		a[3]=1;
	} else {
		a[3]=0;
	}

	if((s1[3]=='A'&& s2[3]=='B')||(s1[3]=='B'&& s2[3]=='A')||(s1[3]=='B'&& s2[3]=='C')||(s1[3]=='C'&& s2[3]=='B')||(s1[3]=='D'&&s2[3]=='C')||(s1[3]=='C'&& s2[3]=='D')||(s1[3]=='D'&& s2[3]=='F')||(s1[3]=='F'&& s2[3]=='D')) {
		a[4]=1;
	} else {
		a[4]=0;
	}
	for(int i=1; i<=4; i++) {
		cout<<a[i];
	}



	return 0;
}