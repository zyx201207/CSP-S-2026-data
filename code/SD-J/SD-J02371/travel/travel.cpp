#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll l,r,x,y;
char a,b;
bool cmp(char u,char v){
	if((u=='A'||u=='B'||u=='C')&&(v=='A'||v=='B'||v=='C')) return true;
	if((u=='D'||u=='F')&&(v=='D'||v=='F')) return true;
	return false;
}
bool pan(char u,char v){
	if((u=='C'&&v=='D')||(u=='D'&&v=='C')) return false;
	if((u=='D'&&v=='F')||(u=='F'&&v=='D')) return true;
	u+=1;
	if(u==v) return true;
	u-=1;
	v+=1;
	if(u==v) return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>l>>r>>a>>x>>y>>b;
//	cout<<l<<" "<<r<<" "<<a<<" "<<x<<" "<<y<<" "<<b<<endl;
	if(l!=x){
		cout<<"0000"<<endl;
	}else{
		if(r!=y){
			cout<<"1000"<<endl;
		}else{
			if(!cmp(a,b)){
				cout<<"1100"<<endl;
			}else{
				if(!pan(a,b)){
					cout<<"1110"<<endl;
				}else{
					cout<<"1111"<<endl;
				}
			}
		}
	}
	return 0;
} 
