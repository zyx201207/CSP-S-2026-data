#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
ll a[N];
char c[N];
string s="1";
ll total=0;
ll ans=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
		total+=a[i];
	}
	ll mid=total/2+1;
	for(int i=mid;i<=total;i++){
		if(s[total-i+1]!=s[i]){
			ans++;
		}
			
	}
	cout<<ans;
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/
