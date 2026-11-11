#include<bits/stdc++.h>
#define up(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define dn(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}
	return x*f;
}
string c_1,s_1,c_2,s_2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool que1=true;
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1==c_2){
		cout<<1;
	}else{
		cout<<0;
		que1=false;
	}
	bool que2=que1?true:false;
	up(i,0,1,1){
		if(s_1[i]!=s_2[i]){
			que2=false;
			break;
		}
	}
	if(que2) cout<<1;
	else cout<<0;
	char x=s_1[2],r=s_2[2];
	bool que3=true;
	if(que2){
		if(x=='A' && (r=='B' || r=='C')){
			cout<<1;
		}else if(x=='B' && (r=='A' || r=='C')){
			cout<<1;
		}else if(x=='C' && (r=='A' || r=='B')){
			cout<<1;
		}else if(x=='D' && r=='F'){
			cout<<1;
		}else if(x=='F' && r=='D'){
			cout<<1;
		}else{
			que3=false;
			cout<<0;
		}
	}else{
		que3=false;
		cout<<0;
	}
	if(que3){
		if(x=='A' && r=='B'){
			cout<<1;
		}else if(x=='B' && r=='C'){
			cout<<1;
		}else if(x=='D' && r=='F'){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	return 0;
}
