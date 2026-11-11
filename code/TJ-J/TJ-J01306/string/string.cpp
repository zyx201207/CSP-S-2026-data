#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
char c[N];
int n,x[N];
string s;
/*
还差一点 
还差一点就不至于绝望
还差一点
就能和他们（dalao）能够站在一起 
（调正解调不出来有感） 

(能上吗QAQ 
*/
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	//f[0]=1;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>c[i];
		for(int j=1;j<=x[i];j++)s+=c[i];
	}
	//cout<<s;
	ll m=s.size();
	ll ans=0;
	for(int i=0;i*2<m;i++)if(s[i]!=s[m-i-1]&&i!=m-i-1)ans++;
	cout<<ans;
	return 0;
}
/*
3
2 a
2 b
1 c

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

8
1 a
2 b
1 c
1 d
1 e
1 a
1 b
1 a
*/
