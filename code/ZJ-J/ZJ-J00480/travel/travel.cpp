#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	for(int i=0;i<2;i++){
		if(a[i]!=c[i]){
			cout<<"0000";
			return 0;
		}
	}
	cout<<"1";
	int flag=1;
	for(int i=0;i<2;i++){
		if(b[i]!=d[i]){
			flag=0;
			break;
		}
	}
	if(flag){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	int n,m;
	n=b[2]-'A'+1;
	m=d[2]-'A'+1;
	if(n<=3&&m<=3){
		cout<<"1";
		if(abs(n-m)==1){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}else if(n>3&&m>3){
		cout<<"11";
	}else{
		cout<<"00";
	}
	return 0;
}
