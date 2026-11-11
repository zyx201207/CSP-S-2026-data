#include<bits/stdc++.h>
using namespace std;
struct tra{
	int wh;
	char ch[3];
};
tra a,b;
int main(){
	freopen("travel.in" );
	cin>>a.wh>>a.ch[0]>>a.ch[1]>>a.ch[2]>>b.wh>>b.ch[0]>>b.ch[1]>>b.ch[2];
	int aw,bw;
	aw=(a.ch[0]-'0')*10+(a.ch[1]-'0');
	bw=(b.ch[0]-'0')*10+(b.ch[1]-'0');
	int a1=a.ch[2]-'A',b1=b.ch[2]-'A';
	if(a.wh==b.wh){
		cout<<1;
		if(aw==bw){
			cout<<1;
			if((a1<3&&b1<3)||(a1>2&&b1>2)){
				cout<<1;
				if(abs(a1-b1)==1)
					cout<<1;
				else cout<<0;
			}else
				cout<<0<<0;
		}else
			cout<<0<<0<<0;
	}else
		cout<<0<<0<<0<<0;
	return 0;
}
