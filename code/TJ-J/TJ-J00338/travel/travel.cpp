#include<bits/stdc++.h>
using namespace std;
//#define int long long
int c1,c2;string s1,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		int s1s=(s1[0]-'0')*10+s1[1]-'0';
		int s2s=(s2[0]-'0')*10+s2[1]-'0';
		if(s1s==s2s){
			cout<<1;
			char sa=s1[2];
			char sb=s2[2];
			if((sa<'D'&&sb<'D')||(sa>='D'&&sb>='D')){
				cout<<1;
				if((sa=='D'&&sb=='F')||(sa=='F'&&sb=='D'))cout<<1;
				else if(abs(sa-sb)==1&&((sa!='C'&&sb!='D')&&(sa!='D'&&sb!='C')))cout<<1;
				else cout<<0;
			}else cout<<0<<0;
		}else cout<<0<<0<<0;
	}else cout<<0<<0<<0<<0;
	return 0;
}
//那个老牧师家长把我PCL2举报了！！！！（中国式家长，很神奇吧） 
//minecraft never die!!!

//上 迷 惑 行 为 大 赏！！！ 
