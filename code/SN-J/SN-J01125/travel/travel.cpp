#include<bits/stdc++.h>
using namespace std;
string rc;
string xc;
string a,b;
string h;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	cin>>a;
	int s,k;
	s=rc.size();
	for(int i=1;i<=s;i++){
		cin>>rc[i];
	}
	cin>>b;
	k=xc.size();
	for(int i=1;i<=k;i++){
		cin>>xc[i];
	}
	if(a==b){
		h[0]=1;
	}else{
		h[0]=0;
	}
	
	if(rc[1]==xc[1] && rc[2]==xc[2]){
		h[1]=1;
	}else{
		h[1]=0;
	}
	if(rc[3]=='A' && xc[3]=='B' || rc[3]=='B'&& xc[3]=='C' || rc[3]=='A' && xc[3]=='C' ||  rc[3]=='D' && xc[3]=='F'){
		h[2]=1;
	}else{
		h[2]=0;
	}
	
	if(rc[3]=='A' && xc[3]=='B' || rc[3]=='B' && xc[3]=='C' || rc[3]=='D' && xc[3]=='F'){
		h[3]=1;
	}else{
		h[3]=0;
	}
	cout<<h; 
	return 0;
}
