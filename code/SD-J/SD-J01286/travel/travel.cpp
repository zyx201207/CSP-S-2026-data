#include<bits/stdc++.h>
#define int long long
using namespace std;
string s1,s2,s3,s4;
int a,b,c,d;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s1>>s2>>s3>>s4;
	for(int i=s1.size()-1;i>=0;i--)a=a*10+s1[i]-'0';
	for(int i=s3.size()-1;i>=0;i--)b=b*10+s3[i]-'0';
	for(int i=s2.size()-2;i>=0;i--)c=c*10+s2[i]-'0';
	for(int i=s4.size()-2;i>=0;i--)d=d*10+s4[i]-'0';
	if(a==b){
		cout<<1;
		if(c==d){
			cout<<1;
			char ch1=s2[s2.size()-1],ch2=s4[s4.size()-1];
			if(('A'<=ch1&&ch1<='C'&&'A'<=ch2&&ch2<='C')||('D'<=ch1&&ch1<='F'&&'D'<=ch2&&ch2<='F')){
				cout<<1;
				if(abs(ch1-ch2)==1)cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
