//SN-J00751   熊凡若    西安市第一中学 
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n=1;
	int u=0,o=1,m=3;
	string c1[2],s1[2],c2[3],s2[3],a[4];
	for(int i=1;i<=1;i++){
	    cin>>c1[i]>>s1[i];
	    cin>>c2[i]>>s2[i];
	        if(c2==s2)
			a[1]+=o;
	        else a[1]+=u;
	        if(c1==c2)a[2]+=o;
	        else a[2]+=u;
	        if(s1[1]==s2[1]||s1[2]==s2[2])
			a[3]+=o;
	        else a[3]+=u;
	        if(c2[m]==s2[m])
			a[4]+=o;
	        else a[4]+=u;
	        cout<<a;
	}
	return 0;
}
