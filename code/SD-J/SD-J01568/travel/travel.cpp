#include<bits/stdc++.h>
using namespace std;
bool cmp1(string a,string b){
	int c[]={1,1,1,2,2};
	return c[a[2]-'A']==c[b[2]-'A']; 
}
bool cmp2(string a,string b){
	char c=a[2],d=b[2];
	if(c=='A'&&d=='B'||c=='B'&&d=='A'){
		return 1;
	}
	if(c=='C'&&d=='B'||c=='B'&&d=='C'){
		return 1;
	}
	if(c=='D'&&d=='F'||c=='F'&&d=='D'){
		return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string Rc,Rs,Xc,Xs;
	cin>>Rc>>Rs>>Xc>>Xs;
	if(Rc==Xc){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(Rc==Xc&&Rs[0]+Rs[1]==Xs[0]+Xs[1]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(Rc==Xc&&Rs[0]+Rs[1]==Xs[0]+Xs[1]&&cmp1(Rs,Xs)){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(Rc==Xc&&Rs[0]+Rs[1]==Xs[0]+Xs[1]&&cmp2(Rs,Xs)){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
