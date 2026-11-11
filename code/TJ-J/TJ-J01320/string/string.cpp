#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
string s,x;
long long r;
int n;
long long a[N],ans = 0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	s = ' '+s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r>>x;
		s = s + x;
		a[i] = r; 
	}
	int i=1,j=n;
	while(i < j){
		if(s[i] != s[j]){
			ans += min(a[i],a[j]);
		}
		long long cha = a[i] - a[j];
		a[j] -= a[i];
		a[i] = cha;
		if(a[i] <= 0) i++;
		if(a[j] <= 0) j--;
	}
	cout<<ans;
	return 0;
}



