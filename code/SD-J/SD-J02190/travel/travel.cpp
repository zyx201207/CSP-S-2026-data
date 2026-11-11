#include<bits/stdc++.h>
#define int long long
using namespace std;
int cx1,cx2,sum1,sum2;
string zw1,zw2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx1>>zw1>>cx2>>zw2;
	if(cx1!=cx2){
		cout<<"0000";
		return 0;
	}else cout<<1;
	for(int i=0;i<=1;i++){
		sum1=sum1*10+(zw1[i]-'0');
		sum2=sum2*10+(zw2[i]-'0');
	}
	if(sum1==sum2){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(zw1[2]=='D'||zw1[2]=='E'){
		if(zw2[2]=='D'||zw2[2]=='E'){
			cout<<11;
		}
		else cout<<"00";
	}
	if(zw1[2]=='A'){
		if(zw2[2]=='B'){
			cout<<"11";
		}else if(zw2[2]=='C'){
			cout<<"10";
		}else cout<<"00";
	}else if(zw1[2]=='B'){
		if(zw2[2]=='A'||zw2[2]=='C'){
			cout<<"11";
		}else cout<<"00";
	}else if(zw1[2]=='C'){
		if(zw2[2]=='B'){
			cout<<"11";
		}else if(zw2[2]=='A'){
			cout<<"10";
		}else cout<<"00";
	}
	return 0;
} //Trick||Treat!
