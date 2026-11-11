#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=2e5+5;
int n;
string s;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	deque<int> l;
	deque<int> r;
	ll len=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	ll jishu=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			if(jishu<len/2)l.push_back(c[i]-'a');
			else if(jishu>len/2)r.push_front(c[i]-'a');
			jishu++;
		}
	}
	ll ans=0;
	while(!l.empty()&&!r.empty()){
		if(l.front()!=r.front()){
			ans++;
		}
		l.pop_front();
		r.pop_front();
	}
	cout<<ans;
	return 0;
}
