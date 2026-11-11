#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int t1=s1[0]*10+s1[1],t2=s2[0]*10+s2[1];
	if(c1==c2){
		cout<<1;
		if(t1==t2){
			cout<<1;
			if(((s1[2]>s2[2])&&s1[2]<='C')||((s2[2]>s1[2])&&s2[2]<='C')||((s1[2]<s2[2])&&s1[2]>='D')||((s2[2]<s1[2])&&s2[2]>='D')){
				cout<<1;
				if((s1[2]==s2[2]+1)||(s1[2]==s2[2]-1)||(s1[2]=='D'&&s2[2]=='F')||(s2[2]=='D'&&s1[2]=='F'))cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	return 0;
}
