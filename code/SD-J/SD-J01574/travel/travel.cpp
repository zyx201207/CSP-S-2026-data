#include <bits/stdc++.h>
using namespace std;
int s1,s2;
char c1[3],c2[3];
int main(){
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s1;
	for (int i=0;i<3;i++) cin>>c1[i];
	cin>>s2;
	for (int i=0;i<3;i++) cin>>c2[i];
	if (s1==s2) cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	if ((c1[0]==c2[0])&&(c1[1]==c2[1])) cout<<1;
	else {
		cout<<"000";
		return 0;
	}
	int l1=c1[2]-'A',l2=c2[2]-'A';
	if ((l1>2)&&(l2>2)) {
		cout<<11;
		return 0;
	}
	if ((l1<3)&&(l2<3)) {
		cout<<1;
		if (((l1-l2)==1)||((l2-l1)==1)) cout<<1;
		else cout<<0;
	}
	else cout<<"00";
	return 0;
}
