#include<bits/stdc++.h>
using namespace std;

int sum,n,ans;
string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	s=" "+s;
	while(n--){
		int x;
		char c;
		cin>>x>>c;
		sum+=x;
		while(x--){
			s=s+c;
		}
	}
	int i=1,j=sum;
	while(i<=j){
		if(s[i]!=s[j]) ans++;
		i++,j--;
	}
	cout<<ans;
	return 0;
}