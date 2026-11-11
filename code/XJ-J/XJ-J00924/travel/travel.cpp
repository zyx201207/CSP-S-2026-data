#include<bits/stdc++.h>;
using namespace std;
string c1,s1,c2,s2,n=17;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1<n||c2<n)cout<<0;
	else if{
		c1=c2;
		cout<<1;
	}
	if(s1=s2)cout<<1;
	else cout<<0;
	if(s1=s2+1||s1+1=s2)cout<<1;
	else cout<<0;
	return 0;
}