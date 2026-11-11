#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rs,rsh,xs,xsh;
	int f=1;
	int fc=1;
	cin>>rs>>rsh>>xs>>xsh;
	for(int i=0;i<rs.size();i++){
		if(rs[i]!=xs[i])f=0;
	}
	fc=f;
	if(f==1)cout<<1;
	
	else cout<<0;
	f=1;
	for(int i=0;i<rsh.size()-1;i++){
		if(rsh[i]!=xsh[i])f=0;
	}
	int fp=f;
	if(f==1&&fc==1)cout<<1;
	else cout<<0;
	f=1;
	for(int i=0;i<rsh.size();i++){
		if(i==rsh.size()-1){
			if(rsh[i]=='D'&&xsh[i]=='A')f=0;
			else if(rsh[i]=='D'&&xsh[i]=='B')f=0;
			else if(rsh[i]=='D'&&xsh[i]=='C')f=0;
			else if(rsh[i]=='F'&&xsh[i]=='A')f=0;
			else if(rsh[i]=='F'&&xsh[i]=='B')f=0;
			else if(rsh[i]=='F'&&xsh[i]=='C')f=0;
			else if(rsh[i]=='A'&&xsh[i]=='D')f=0;
			else if(rsh[i]=='B'&&xsh[i]=='D')f=0;
			else if(rsh[i]=='C'&&xsh[i]=='D')f=0;
			else if(rsh[i]=='A'&&xsh[i]=='F')f=0;
			else if(rsh[i]=='B'&&xsh[i]=='F')f=0;
			else if(rsh[i]=='C'&&xsh[i]=='F')f=0;
		}
	}
	if(f==1&&fc==1&&fp==1)cout<<1;
	else cout<<0;
	f=1;
	for(int i=0;i<rsh.size();i++){
		if(rsh[i]!=xsh[i]&&i!=rsh.size()-1)f=0;
		if(i==rsh.size()-1){
			if(rsh[i]=='D'&&xsh[i]=='A')f=0;
			else if(rsh[i]=='D'&&xsh[i]=='B')f=0;
			else if(rsh[i]=='D'&&xsh[i]=='C')f=0;
			else if(rsh[i]=='D'&&xsh[i]=='D')f=0;
			else if(rsh[i]=='F'&&xsh[i]=='A')f=0;
			else if(rsh[i]=='F'&&xsh[i]=='B')f=0;
			else if(rsh[i]=='F'&&xsh[i]=='C')f=0;
			else if(rsh[i]=='F'&&xsh[i]=='F')f=0;
			else if(rsh[i]=='A'&&xsh[i]=='C')f=0;
			else if(rsh[i]=='A'&&xsh[i]=='D')f=0;
			else if(rsh[i]=='A'&&xsh[i]=='F')f=0;
			else if(rsh[i]=='A'&&xsh[i]=='A')f=0;
			else if(rsh[i]=='B'&&xsh[i]=='B')f=0;
			else if(rsh[i]=='B'&&xsh[i]=='D')f=0;
			else if(rsh[i]=='B'&&xsh[i]=='F')f=0;
			else if(rsh[i]=='C'&&xsh[i]=='C')f=0;
			else if(rsh[i]=='C'&&xsh[i]=='A')f=0;
			else if(rsh[i]=='C'&&xsh[i]=='D')f=0;
			else if(rsh[i]=='C'&&xsh[i]=='F')f=0;
		}
	}
	if(f==1&&fc==1)cout<<1;
	else cout<<0;
	return 0;
}
