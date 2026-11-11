#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	float rx,rz,xx,xz;
	cin>>rx>>rz>>xx>>xz;
	if(17-rx+xx==17-rx)cout<<1;
	else{
		cout<<0;
	}
	if(rz-xz<=4||xz-rz<=4&&xz-rz!=0) cout<<1;
	else{
		cout<<0;
	}
	if(rz-xz<2||xz-rz<2&&rz-xz!=0){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(rz-xz==1||xz-rz==1&&rz-xz!=0) cout<<1;
	else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
