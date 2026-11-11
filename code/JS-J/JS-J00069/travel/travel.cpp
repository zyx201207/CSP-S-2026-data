#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ull unsigned long long 
#define db double 




int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int r1,r2;
	string s1,s2;
	cin>>r1>>s1>>r2>>s2;
	int c1,c2;
	c1=s1[0]*10+s1[1];
	c2=s2[0]*10+s2[1];
	bool f1=r1 == r2,f2=c1 == c2,f3=(s1[2] <= 'C' && s2[2] <= 'C' ) || (s1[2] >= 'D' && s2[2] >= 'D'),f4=abs(s1[2]-s2[2]) == 1;
	if(f1) cout<<1;
	else cout<<0;
	if(f1 && f2) cout<<1;
	else cout<<0;
	if(f1 && f2 && f3) cout<<1;
	else cout<<0;
	if(f1 && f2 && f3 && f4) cout<<1;
	else cout<<0;
	
	
	
	
	
	return 0;
}

