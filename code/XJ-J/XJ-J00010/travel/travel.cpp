#include<bits/stdc++.h>
using namespace std;
int sum[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,a1,b,b1;
	cin>>a>>a1>>b>>b1;
	
	int a2=int(a[0])*10,b2=int(b[0])*10;
	a2+=int(a[1]),b2+=int(b[1]);
	
	if(a2==b2){
		sum[0]=1;
	
		if(a1[1]==b1[1]&&a1[0]==b1[0]){
			sum[1]=1;
				int ce=0,ca=0;
			if(a1[2]=='D'||a1[2]=='F'){
				ce=1;
			}else{
				ce=0;
			}
			if(b1[2]=='D'||b1[2]=='F'){
				ca=1;
			}else{
				ca=0;
			}
			if(ce==ca){
				sum[2]=1;
				int y=abs(a1[2]-b1[2]);
				if(y==1){
					sum[3]=1;
				}else{
					sum[3]=0;
				}
			}else{
				sum[2]=0;
				sum[3]=0;
		
			}
		}else{
			sum[1]=0;
			sum[2]=0;
			sum[3]=0;
		}
		
	}else{
		sum[0]=0;
		sum[1]=0;
		sum[2]=0;
		sum[3]=0;
	}
	
	cout<<sum[0]<<sum[1]<<sum[2]<<sum[3];
	return 0;
}