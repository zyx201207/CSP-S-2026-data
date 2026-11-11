#include <bits/stdc++.h>
using namespace std;
int ads(int n){
	if(n>=0)
	return n;
	else 
	return -n;
	
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
string a,s,d,f;
int j=0,k=1,l=0,t=0;
cin>>a>>s>>d>>f;

if(a==d)
j=1;
cout<<j;
	for(int i=0;i<2;i++){
		if(s[i]!=f[i])
			k=0;
	}
cout<<k;

		if(	k=1&&(((s[2]=='A'||'B'||'C')&&(f[2]=='A'||'B'||'C'))||((s[2]=='D'||'F')&&(f[2]=='D'||'F'))))
		
		l=1;
	

		if(ads(s[2]-f[2])==1)
			t=1;
	
cout<<j<<k<<l<<t;
return 0;
}
