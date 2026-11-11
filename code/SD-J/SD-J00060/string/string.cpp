#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,a[N],ans;
char c[N];
string s,t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	t=s;
	reverse(s.begin(),s.end());
	int lens=s.size()/2;
	for(int i=0;i<lens;i++){
		if(s[i]!=t[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
