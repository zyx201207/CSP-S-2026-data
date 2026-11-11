#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
unsigned int num(string c){
	unsigned int r=0;
	for (int i=0;i<c.length();i++) r=r*10+(c[i]-'0');
	return r;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(false);
	cin>>c1>>s1>>c2>>s2;
	unsigned int cR=num(c1),cX=num(c2);
	if (cR==cX){
		cout<<1;
		unsigned int sR1=(s1[0]-'0')*10+(s1[1]-'0'),sX1=(s2[0]-'0')*10+(s2[1]-'0');
		char c[2]={s1[2],s2[2]};
		sort(c,c+2);
		if (sR1==sX1) {
			cout<<1<<(c[1]<='C'||c[0]>='D');
		} else cout<<"00";
		if (abs(sR1-sX1)==1&&s1[2]==s2[2]) cout<<1;
		else if (sR1==sX1) {
			char c[2]={s1[2],s2[2]};
			sort(c,c+2);
			if ((c[1]-c[0]==1&&c[0]!='C')||(c[0]=='D'&&c[1]=='F')) cout<<1;
			else cout<<0;
		} else cout<<0;
	} else cout<<"0000"<<endl;
	fclose(stdin); fclose(stdout);
	return 0;
}
