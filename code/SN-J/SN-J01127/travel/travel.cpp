#include <bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2,b,a;
char c,s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int f=0,l=0,k=0,m=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) f=1;
	int ma=max(s1.size(),s2.size());
	for(int i=0;i<ma;i++){
		if(s1[i]>='0'&&s1[i]<='9') b+=s1[i];
		if(s2[i]>='0'&&s2[i]<='9') a+=s2[i];
		if(s1[i]>='A'&&s1[i]<='Z') c=s1[i];
		if(s2[i]>='A'&&s2[i]<='Z') s=s2[i];
	}
	if(b==a) l=1;
	if((c<='C'&&s<='C'&&l==1)||(c>='D'&&s>='D'&&l==1)) k=1;
	if((c-s==1&&k==1)||(s-c==1&&k==1)) m=1;
	cout<<f<<l<<k<<m;
	return 0;
} 
