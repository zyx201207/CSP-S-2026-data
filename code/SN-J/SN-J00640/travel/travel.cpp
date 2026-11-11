// 李思齐 陕西省西安爱知中学 SN-J00640 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
char aline[10]={'A','B','C','D','E'};
string a,b,n,m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b>>n>>m; 
	if(a==n)cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	if(b[1]==m[1]&&b[0]==m[0])cout<<1;
	else{
		cout<<"000";
		return 0;                                                
	}
	int ali=0,bli=0;
	for(int i=0;i<=4;i++){
		if(b[2]==aline[i])ali=i+1;
		if(m[2]==aline[i])bli=i+1;
	}
	if((ali<=3&&bli<=3)||(ali>3&&bli>3)){
		cout<<1;
		if(ali>3&&bli>3)cout<<1;
		else if(ali==bli-1||ali==bli+1)cout<<1;
		else cout<<0;
	}else cout<<0<<0;
	return 0;
}
