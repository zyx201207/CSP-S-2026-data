#include <iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	int n[10]={0,0,0,0};
	cin>>a>>b>>c>>d;
	if(a==c){
		n[0]+=1;
		if(b[0]==d[0]&&b[1]==d[1]){
			n[1]+=1;
			if(b[2]=='A'){
				if(b[2]+2==d[2]){
					n[2]+=1;
					}
				if(b[2]+1==d[2]){
					n[2]+=1;
					n[3]+=1;
				}
				}
			if(b[2]=='B'){
				if(b[2]+1==d[2]||b[2]-1==d[2]){
					n[2]+=1;
					n[3]+=1;
				}
			}
			if(b[2]=='C'){
				if(b[2]-2==d[2]){
					n[2]+=1;
				}
				if(b[2]-1==d[2]){
					n[2]+=1;
					n[3]+=1;
				}
			}
			if(b[2]=='D'||b[2]=='F'){
				if(b[2]+1==d[2]||b[2]-1==d[2]){
					n[2]+=1;
					n[3]+=1;
				}
			}
		}
		cout<<n[0]<<n[1]<<n[2]<<n[3];
	}
	else{
		cout<<n[0]<<n[1]<<n[2]<<n[3];
	}
	return 0;
}
