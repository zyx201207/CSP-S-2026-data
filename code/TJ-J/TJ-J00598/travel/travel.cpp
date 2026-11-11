#include <bits/stdc++.h>
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	char abc[3]={'A','B','C'},df[2]={'D','F'};
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}else {
		cout<<"000"; 
		return 0;
	}
	for(int i=0;i<3;i++){
		int n=0;
		if(s1[2]==abc[i] || s2[2]== abc[i]){
		    cout<<1;
		    n++;
		    break;
		}
		if(s1[2]==df[i] || s2[2]==df[i]){
		   	cout<<1;
		   	n++;
		   	break;
		}
		if(i==2 && n==0){
			cout<<"00";
			return 0;
		}
	}
	if(int(s1[2])+1==s2[2]|| int(s1[2]-1)==s2[2]){
		cout<<"1";
	}else cout<<"0"; return 0;
	
	return 0;
}
