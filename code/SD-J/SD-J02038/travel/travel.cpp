#include<bits/stdc++.h>
using namespace std;
int tr,srx,sry,tx,sxx,sxy,cnt,i,t=1,l;
string a,c;
int ans[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c;
	tr=(a[0]-'0')*10+a[1]-'0';
	srx=(c[0]-'0')*10+c[1]-'0';
	sry=c[2]-'A'+1;
	cin>>a>>c;
	tx=(a[0]-'0')*10+a[1]-'0';
	sxx=(c[0]-'0')*10+c[1]-'0';
	sxy=c[2]-'A'+1;
	if(tr==tx){
		ans[1]=1;
		if(srx==sxx){
			ans[2]=1;
			if((sry<=3&&sxy<=3)||(sry>3&&sxy>3)){
				ans[3]=1;
				if(sry-sxy==1||sxy-sry==1){
					ans[4]=1; 
				}
			}
		}
	}
	cout<<ans[1]<<ans[2]<<ans[3]<<ans[4];
	return 0;
} 
