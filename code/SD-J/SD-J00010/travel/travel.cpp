#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
long long www,fff,q,rrr;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	long long dy=(a[0]-48)*10+(a[1]-48);
	long long du=(c[0]-48)*10+(c[1]-48);
	if(dy==du){
		cout<<1;
	}else{
		cout<<0;
	}
	rrr=(b[0]-48)*10+(b[1]-48);
	www=(d[0]-48)*10+(d[1]-48);
	if(rrr==www and dy==du){
		cout<<1;
	}else{
		cout<<0;
	}
	if(b[2]=='A' and d[2]=='B'){
		fff=1;
	}
	if(b[2]=='A' and d[2]=='C'){
		fff=1;
	}
	if(b[2]=='B' and d[2]=='C'){
		fff=1;
	}
	if(b[2]=='D' and d[2]=='F'){
		fff=1;
	}
	if(b[2]=='B' and d[2]=='A'){
		fff=1;
	}
	if(b[2]=='C' and d[2]=='A'){
		fff=1;
	}
	if(b[2]=='C' and d[2]=='B'){
		fff=1;
	}
	if(b[2]=='F' and d[2]=='D'){
		fff=1;
	}
	if(rrr==www and fff==1){
		if(du==dy){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	if(b[2]=='A' and d[2]=='B'){
		q=1;
	}
	if(b[2]=='B' and d[2]=='C'){
		q=1;
	}
	if(b[2]=='D' and d[2]=='F'){
		q=1;
	}
	if(b[2]=='B' and d[2]=='A'){
		q=1;
	}
	if(b[2]=='C' and d[2]=='B'){
		q=1;
	}
	if(b[2]=='F' and d[2]=='D'){
		q=1;
	}
	if(q==1 and fff==1){
		if(www==rrr and du==dy){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
}
