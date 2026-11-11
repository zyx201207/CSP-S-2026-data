#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char r[3],x[3];
	int r1,x1;
	bool b1,b2,b3,b4;
	b1=b2=b3=b4=0;
	cin>>r1>>r>>x1>>x;
	if(r1==x1){
		b1=1;
		bool f=1;
		for(int i=0;i<2;i++){
			if(r[i]!=x[i]){
				f=0;
			}
		}
		if(f){
			b2=1;
			if((r[2]<='C'&&x[2]<='C')||(r[2]>'C'&&x[2]>'C')){
				b3=1;
				if(r[2]+1==x[2]+0||r[2]-1==x[2]-0){
					b4=1;
				}
			}
		}
	}
	cout<<b1<<b2<<b3<<b4;
	return 0;
} 
