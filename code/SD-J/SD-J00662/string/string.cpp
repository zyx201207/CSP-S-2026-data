#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,a[N],ans;
string s,c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(long long j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	long long r=s.size()-1,l=0;
	while(r>l){
		if(s[r]==s[l]){
			r--;
			l++;
			continue;
		}
		else{
			r--;
			l++;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
