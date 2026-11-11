#include<iostream>
#include<cstdio>
using namespace std;
bool train(string a,string b){
	if(a[0]!=b[0]){
		return 0;
	}
	else if(a[1]!=b[1]){
		return 0;
	}
	return 1;
}
bool pai(string a,string b){
	if(a[0]!=b[0]){
		return 0;
	}
	else if(a[1]!=b[1]){
		return 0;
	}
	return 1;
}
bool side(string a,string b){
	if((a[2]=='D' && b[2]=='F')||
	(a[2]=='F' && b[2]=='D')){
		return 1;
	}
	else if((a[2]!='D'&&a[2]!='F'&&b[2]=='F')||
	(a[2]!='D'&&a[2]!='F'&&b[2]=='D')||
	(b[2]!='D'&&b[2]!='F'&&a[2]=='F')||
	(b[2]!='D'&&b[2]!='F'&&a[2]=='D')){
		return 0;
	}
	else if((a[2]=='D'&&b[2]!='F')||
	(a[2]=='F'&&b[2]!='D')||
    (b[2]=='D'&&a[2]!='F')||
	(b[2]=='F'&&a[2]!='D')){
	
		return 0;
	}
	return 1;
}
bool seat(string a,string b){
	if((a[2]==b[2]-1)||a[2]==b[2]+1){
		return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1;
	cin>>c1>>s1;
	string c2,s2;
	cin>>c2>>s2;
	bool bb=true;
	for(int i=1;i<=4;i++){
		if(bb==false){
			cout<<0;
			continue;
		}
		if(i==1){
			if(train(c1,c2)==1){
				cout<<1;
			}
			else{
				cout<<0;
				bb=false;
			}
		}
		if(i==2){
			if(pai(s1,s2)==1){
				cout<<1;
			}
			else{
				cout<<0;
				bb=false;
			}
		}
		if(i==3){
			if(side(s1,s2)==1){
				cout<<1;
			}
			else{
				cout<<0;
				bb=false;
			}
		}
		if(i==4){
			if(seat(s1,s2)==1){
				cout<<1;
			}
			else{
				cout<<0;
				bb=false;
			}
		}
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
