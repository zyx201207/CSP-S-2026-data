#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c) cout<<"0000";
	else{
		if(b[0]!=d[0] or b[1]!=d[1]){
			cout<<"1000";
			return 0;
		}char c1=b[2],c2=d[2];
		int p1=c1-'C',p2=c2-'C';
		if((p1>0 and p2>0) or (p1<=0 and p2<=0)){
			if(p1>0 and p2>0){
				cout<<"1111";
			}else if(p1==p2+1 or p2==p1+1){
				cout<<"1111";
			}else cout<<"1110";
		}else cout<<"1100";
	}
	return 0;
} 
