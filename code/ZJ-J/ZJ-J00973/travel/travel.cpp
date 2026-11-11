#include<bits/stdc++.h>
using namespace std;

using ll=long long;

ll read(){
	ll ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

pair<ll,ll> get(string s){
	ll row=0,ptr=0;
	while(isdigit(s[ptr])) row=row*10+s[ptr]-'0',ptr++;
	ll pos;
	if(s[ptr]=='F') pos=5;
	else pos=s[ptr]-'A'+1;
	return {row,pos};
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ll c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
//	cout<<c1<<','<<c2<<'\n';
	bool flg1,flg2,flg3,flg4;
	flg1=(c1==c2);
	ll row1,row2,pos1,pos2;
	auto cur1=get(s1),cur2=get(s2);
	row1=cur1.first,row2=cur2.first,pos1=cur1.second,pos2=cur2.second;
	flg2=(flg1&&row1==row2);
	flg3=(flg1&&flg2&&((pos1<=3&&pos2<=3)||(pos1>=4&&pos2>=4)));
	flg4=(flg1&&flg2&&flg3&&abs(pos1-pos2)==1);
	cout<<flg1<<flg2<<flg3<<flg4;
	return 0;
}
