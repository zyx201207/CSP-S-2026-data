#include<bits/stdc++.h>
using namespace std;
char c[15];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(int i=1;i<=10;i++)cin>>c[i];
	if(c[1]==c[6]&&c[2]==c[7]){
		cout<<1;
		if(c[3]==c[8]&&c[4]==c[9]){
			cout<<1;
			if(c[5]>='A'&&c[5]<='C'&&c[10]>='A'&&c[10]<='C'){
				cout<<1;
				if(c[5]=='B'||c[10]=='B'){
					cout<<1;
				}else cout<<50;
			}else if(c[5]>='D'&&c[5]<='F'&&c[10]>='D'&&c[10]<='F'){
				cout<<11;
			}else cout<<0<<0;
		}else cout<<0<<0<<0;
	}else cout<<0<<0<<0<<0;
	return 0;//there is Chengdu
} 
