#include<bits/stdc++.h>
using namespace std;
string ca,sa,cb,sb;
int s[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>sa>>cb>>sb;
	if(ca==cb) s[0]=1;
	if(sa[0]==sb[0]&&sa[1]==sb[1]&&s[0]==1) s[1]=1;
	if(sa[2]+sb[2]<='A'+'C'&&s[0]==1&&s[1]==1||sa[2]+sb[2]=='D'+'E'&&s[0]==1&&s[1]==1) s[2]=1;
	if(sa[2]-sb[2]==1&&s[0]==1&&s[1]==1||sa[2]-sb[2]==-1&&s[0]==1&&s[1]==1) s[3]=1;
	for(int i=0;i<=3;i++) cout<<s[i];
	return 0;
}