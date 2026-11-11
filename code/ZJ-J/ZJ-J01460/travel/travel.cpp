#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<"1";
    else{
    	cout<<"0000";
    	return 0;
	} 
    int pr=(s1[0]*10+s1[1]),px=(s2[0]*10+s2[1]);
	if(pr==px){
		 cout<<"1";
		 if((s1[2]>='A' && s1[2]<='C' && s2[2]>='A' && s2[2]<='C') || (s1[2]>='D' && s1[2]<='E' && s2[2]>='D' && s2[2]<='E')){
			  cout<<"1";
			  int lr=int(s1[2]),lx=int(s2[2]);
			  if(abs(lr-lx)==1) cout<<"1";
			  else cout<<"0";
		  }
		 else cout<<"00";
		 
	 }
	else cout<<"000";
    return 0;
}
