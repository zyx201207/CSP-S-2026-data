#include<bits/stdc++.h>
using namespace std;
long long rh[5],xh[5];
long long ans1,ans2,ans3,ans4;
long long rc,xc;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>xc;
	if(rc==xc){
		ans1=1;
		for(int i=1;i<=5;i++){
		cin>>rh[i];
		for(int j=1;j<=5;j++){
			cin>>xh[j];
			if(rh[1]==xh[1]&&rh[2]==xh[2]){
				ans2=1;
				if(rh[3]=='A'||rh[3]=='B'||rh[3]=='C'&&xh[3]=='A'||xh[3]=='B'||xh[3]=='C'){
					ans3=1;
				}else{
					if(rh[3]=='D'&&xh[3]=='F'||rh[3]=='F'&&xh[3]=='D'){
						ans3=1;
						if(rh[3]=='A'&&xh[3]=='B'||rh[3]=='B'&&xh[3]=='C'||rh[3]=='D'&&xh[3]=='F'){
							ans4=1;
						}else{
							ans4=0;
						}
					}else{
						ans3=0;
					}
				}
			}else{
				ans2=0;
			}
		}
	}
	}else{
		ans1=0;
	}
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}
