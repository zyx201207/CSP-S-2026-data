#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0), cout.tie(0);
	string s1,s2,c1,c2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	} 
	string cnt,sum;
	for(int i=0;i<=2;i++){
		if(isdigit(s1[i])){
			cnt+=s1[i];
		}
	} 
	for(int i=0;i<=2;i++){
		if(isdigit(s2[i])){
			sum+=s2[i];
		}
	} 
	if(cnt==sum) cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	int a,b;
	a=s1[2]-'A',b=s2[2]-'A';
	if(a<=2 && b<=2 || a>2 && b>2) cout<<1;
	else{
		cout<<0<<0;
		return 0;
	}
	if(b-a==1 && a<=2 && b<=2 || b-a==1 && a>2 && b>2) cout<<1;
	else cout<<0;
	return 0;
}
