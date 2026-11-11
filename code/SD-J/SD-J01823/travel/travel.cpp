#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000"<<endl;
		return 0;
	}else {
		cout<<"1";
		if((s1[0]==s2[0])&&(s1[1]==s2[1]))cout<<"1";
		else {
			cout<<"000";
			return 0;
	    }
		int l=0,r=0;
		for(int i=0;i<5;i++){
			char x='A'+i;
			if(s2[2]==x)l=(i+1)/4;
			if(s1[2]==x)r=(i+1)/4; 
		}
		if(l==r)cout<<"1";
		else {
			cout<<"00";
			return 0;
	    }
		if(l!=r)cout<<"0";
		else {
			int k=int(s1[2]-s2[2]);
			if(abs(k)==1)cout<<"1";
			else cout<<"0";
		}
	}
	cout<<endl;
	return 0;
}
