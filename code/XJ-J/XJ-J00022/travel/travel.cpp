#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool b[4]={0};
	int a1,a2,b1,b2,c,d;
	char ax,bx;
	cin>>a1>>a2>>ax>>b1>>b2>>bx;
	c=ax-'A'+1;
	d=bx-'A'+1;
	if(a1==b1){
		b[0]=1;
		if(a2==b2){
			b[1]=1;
			if((c<4&&d<4)||(c>3&&d>3)){
				b[2]=1;
				if((abs(c-d)==1)&&!((c==4&&d==3)||(c==3&&d==4))){
					b[3]=1;
				}
			}
		}
	}
	cout<<b[0]<<b[1]<<b[2]<<b[3];
	return 0;
}
