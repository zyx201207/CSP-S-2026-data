#include<bits/stdc++.h>
using namespace std;
long long cx1,cx2,an1[2],an2[2],ann1,ann2,ans;
string zw1,zw2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>cx1>>zw1>>cx2>>zw2;
	if(cx1==cx2)
		cout<<"1";
	else{
		cout<<"0000";
		return 0;	
	}
	for(int i=0;i<2;i++){
		an1[i]=zw1[i];
		an2[i]=zw2[i];
	}
	ann1=an1[0]*10+an1[1];
	ann2=an2[0]*10+an2[1];
	if(ann1==ann2)
		cout<<"1";
	else{
		cout<<"000";
		return 0;	
	} 
	if(zw1[2]>='A'&&zw1[2]<='C'&&zw2[2]>='A'&&zw2[2]<='C'||zw1[2]>='D'&&zw1[2]<='F'&&zw2[2]>='D'&&zw2[2]<='F'){
		cout<<"1";
		ans=1;
	}
	else{
		cout<<"00";
		return 0;
	}
	
	if(ans==1&&zw1[2]>='D'&&zw1[2]>='F')
		cout<<"1";
	else if(zw1[2]=='C'&&zw2[2]=='D'||zw1[2]=='D'&&zw2[2]=='C')
		cout<<"0";
	else if(max(zw1[2],zw2[2])-min(zw1[2],zw2[2])==1)
		cout<<"1";
	else
		cout<<"0";
	return 0;
}
