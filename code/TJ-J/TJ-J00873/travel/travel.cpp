#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,n1;
	string m,m1;
	bool flag1=0,flag2=0,flag3=0,flag4=0;
	cin>>n>>m>>n1>>m1;
	if(n==n1){
		flag1=1;
		if(m[0]+m[1]==m1[0]+m1[1]){
			flag2=1;
			if((m[2]>='D'&&m1[2]>='D')||(m[2]<='C'&&m1[2]<='C')){
				flag3=1;
				if(abs(m[2]-m1[2])==1){
					flag4=1;
				}
			}
		}
	}
	cout<<flag1<<flag2<<flag3<<flag4;
	return 0;
}
