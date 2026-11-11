#include<iostream>
using namespace std;
string c1,s1,c2,s2;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    cout<<(c1==c2?1:0);
    if(c1==c2 and s1[0]==s2[0] and s2[1]==s1[1]){
	    if( (s1[2]<='C' and s2[2]<='C') or (s2[2]>='D' and s2[2]>='D'))
		    if(abs(s2[2]-s1[2])==1) 
		    	cout<<"111";
		    else cout<<"110";
	    else cout<<"100";
    }
    else cout<<"000";
   cout<<endl;
   return 0;
}

 

