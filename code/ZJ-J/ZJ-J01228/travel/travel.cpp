#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,e,f;
bool f89;
char aer[3]={'A','B','C'},aer2[2]={'D','F'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	for(int i=0;i<max(a.size(),c.size());i++){
		if(a[i]!=c[i]){
			f89=1;
			break;
		}
	}
	if(f89==1){
		cout<<"0000";
		return 0;
	}
	else cout<<1;
	for(int i=0;i<b.size()-1;i++) e+=b[i];
	for(int i=0;i<d.size()-1;i++) f+=d[i];
	if(e==f) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	int de=0,de2=0;
	char o=b[b.size()-1],k=d[d.size()-1];
	for(int i=0;i<=2;i++){
		if(o==aer[i]){
			de=1;
		}
		if(k==aer[i]){
			de2=1;
		}
	}
	if(de==0) de=2;
	if(de2==0) de2=2;
	if(de==de2) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(o=='A'&&k=='B') cout<<1;
	else if(o=='B'&&(k=='A'||k=='C')) cout<<1;
	else if(o=='C'&&k=='B') cout<<1;
	else if(o=='D'&&k=='F') cout<<1;
	else if(o=='F'&&k=='D') cout<<1;
	else cout<<0; 
	return 0;
}
