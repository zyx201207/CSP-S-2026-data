#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
string s1="";
int a,b,d=0;
char c;
cin>>a;
for(int i=1;i<=a;i++)
{
	cin>>b>>c;
	for(int v=1;v<=b;v++){
		s1+=c;
	}
	d+=b;
}
int p;
if(d%2==0)
 p=d/2;
else
 p=d/2+1;
int m=p;
for(int i=0;i<p;i++){
	if(s1[i]==s1[b-i+1]) m--;
}
cout<<m;
	return 0;
}