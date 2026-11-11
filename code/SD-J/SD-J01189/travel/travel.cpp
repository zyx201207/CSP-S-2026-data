#include<bits/stdc++.h>
using namespace std;
string a,b;
char c[]={'0','A','B','C','D','E'};
int ac=0,bc=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>ac>>a>>bc>>b;
	if(ac!=bc){
		cout<<0<<0<<0<<0;
		return 0;
	}
	else{
		cout<<1;
		int ca=(a[0]-'0')*10+(a[1]-'0');
		int cb=(b[0]-'0')*10+(b[1]-'0');
		if(ca!=cb){
			cout<<0<<0<<0;
			return 0;
		}
		else{
			cout<<1;
			char aac=a[2];
			char bbc=b[2];
			int aaa=0,bbb=0;
			for(int i=1;i<=5;i++){
				if(c[i]==aac){
					aaa=i;
				}
				else if(c[i]==bbc){
					bbb=i;
				}
			}
			if((aaa<=3&&bbb<=3)||(aaa>3&&bbb>3)){
				cout<<1;
				if(aaa+1==bbb||aaa-1==bbb){
					cout<<1;
					return 0;
				}
				else{
					cout<<0;
					return 0;
				}
			}
			else{
				cout<<0<<0;
				return 0;
			}
		}
	}
	return 0;
} 
