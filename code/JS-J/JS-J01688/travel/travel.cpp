#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,a2,a3,b1,b2,b3;
	string as,bs;
	cin>>a1>>as>>b1>>bs;
	a2=(as[0]-'0')*10+as[1]-'0',a3=as[2]-'A';
	b2=(bs[0]-'0')*10+bs[1]-'0',b3=bs[2]-'A';
	if(a1==b1){
		cout<<1;
		if(a2==b2){
			cout<<1;
			if((a3<3&&b3<3)||(a3>2&&b3>2)){
				cout<<1;
				if(a3==b3+1||a3==b3-1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<0<<0;
			}
		}
		else{
			cout<<0<<0<<0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}
