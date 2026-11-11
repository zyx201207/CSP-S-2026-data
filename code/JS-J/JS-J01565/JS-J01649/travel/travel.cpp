#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		
		return 0;
	}
	cout<<1;
	string s3="",s4="";
	for(int i=0;i<=1;i++){
		s3+=s1[i];
		s4+=s2[i];
	}
	
	if(s3!=s4){
		cout<<"000";
		return 0;
	}
	cout<<1;
	char c3=s1[s1.size()-1],c4=s2[s2.size()-1];
	if((c3=='A'||c3=='B'||c3=='C')&&(c4=='D'||c4=='F')){
			cout<<"00";
			return 0;
	}
	if((c4=='A'||c4=='B'||c4=='C')&&(c3=='D'||c3=='F')){
			cout<<"00";
			return 0;
	}
	cout<<1;
	if(c4=='D'||c4=='F'){
		cout<<1;
	}else{
		if(c3>c4){
			swap(c3,c4);
		}
		if((c3=='A'&&c4=='B')||(c3=='B'&&c4=='C')){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0;
}
