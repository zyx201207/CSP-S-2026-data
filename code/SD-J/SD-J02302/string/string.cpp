#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e7+10;
int n,a[N],cnt=0;
char c[N];
signed main(){

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int b=1,d=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	string s;
	for(int i=1;i<=n;i++){
		s[b]=c[i];
		d++;
		if(d<a[i]){
			i--;
		}else{
			d=0;
		}
		b++;
	}
	b=b-1;
	for(int i=1;i<=b;i++){
		if(s[i]!=s[b-i+1]){
			cnt++;
			s[i]=s[b-i+1];
		}
	}
//	for(int i=1;i<=b;i++){
//		cout<<s[i];
//	}
	cout<<cnt;



	
	

	return 0;
}
/*
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

3
2 a
2 b
1 c


*/

