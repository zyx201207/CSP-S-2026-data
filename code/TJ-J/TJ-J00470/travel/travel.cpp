#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000"<<endl;
		return 0;
	}
	if(s1[1]==s2[1]&&s1[0]==s2[0]){
		cout<<1;
	}else{
		cout<<"000"<<endl;
		return 0;
	}
	int ss,sss;
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		ss=1;
	}else{
		ss=0;
	}
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
		sss=1;
	}else{
		sss=0;
	}
	if(ss==sss){
		cout<<1;
	}else{
		cout<<"00"<<endl;
		return 0;
	}
	if(int(s1[2])-int(s2[2])==1||int(s1[2])-int(s2[2])==-1){
		cout<<1<<endl;
	}else{
		cout<<0<<endl;
	}
	return 0;
}
//7199
