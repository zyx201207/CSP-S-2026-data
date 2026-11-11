#include<bits/stdc++.h>
using namespace std;
//guodedaima
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int len1=c1.size(),len2=s1.size(),len3=c2.size(),len4=s2.size();
	int f1=0,f2=0,f3=0,f4=0;
	if(c1==c2){
		f1=1;
	}
	string t1=s1.substr(0,len2-1);
	string t2=s2.substr(0,len4-1);
	if(f1==1&&t1==t2){
		f2=1;
	}
	if(f2==1&&((s1[len2-1]>='A'&&s1[len2-1]<='C'&&s2[len4-1]>='A'&&s2[len4-1]<='C')||(s1[len2-1]>='D'&&s1[len2-1]<='F'&&s2[len4-1]>='D'&&s2[len4-1]<='F'))){
		f3=1;
	}
	if(f3==1&&((char(s1[len2-1]+1)==s2[len4-1])||(char(s1[len2-1]-1)==s2[len4-1]))){
		f4=1;
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
}