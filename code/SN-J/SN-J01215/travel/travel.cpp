#include<bits/stdc++.h>
using namespace std;
//9:00   实际 8:47    13分差， 
int main()
{
//	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string sa,sb;
	cin>>a>>sa>>b>>sb;
	if(a==b) cout<<1;
	else{
		for(int i=1;i<=4;i++) cout<<0;
		return 0;
	} 
	int la=0,lb=0;//排
	if(sa[0]=='1') la+=10;
	if(sb[0]=='1') lb+=10;
	la+=sa[1]-'0';
	lb+=sb[1]-'0'; 
	if(la==lb) cout<<1;
	else{
		for(int i=1;i<=3;i++) cout<<0;
		return 0;
	}
	char aa=sa[2],ab=sb[2];//作为
	if((aa<='C'&&ab<='C')||(aa>='D'&&ab>='D')) cout<<1;
	else{
		for(int i=1;i<=2;i++) cout<<0;
		return 0;
	}
	if(aa>ab) swap(aa,ab);
	if(aa>='D'){
		if(aa=='D'&&ab=='F') cout<<1;
		else cout<<0;
	}else{
		if(ab-aa==1) cout<<1;
		else cout<<0;
	}
	return 0;
}
// 02 01F 02 01D
