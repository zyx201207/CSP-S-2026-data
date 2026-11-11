#include<bits/stdc++.h>
#define ll long long
#define mes(a,b) memset(a,b,sizeof a);
using namespace std;
struct node{
	int cx,n;
	char ch;
}R,X;
string c2,c4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>R.cx>>c2>>X.cx>>c4;
	if(R.cx==X.cx){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	for(auto c:c2){
		if(c>='A'&&c<='Z'){
			R.ch=c;
		}else{
			R.n+=c-'0';
		}
	}
	for(auto c:c4){
		if(c>='A'&&c<='Z'){
			X.ch=c;
		}else{
			X.n+=c-'0';
		}
	}
	if(R.n==X.n){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(R.ch!='D'&&R.ch!='F'&&X.ch!='D'&&X.ch!='F'){
		cout<<1;
	}else if((R.ch=='D'||R.ch=='F')&&(X.ch=='D'||X.ch=='F')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(R.ch-X.ch)==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
