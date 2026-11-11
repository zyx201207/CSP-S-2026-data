#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N];
long long sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string c="";
	for(int i=1;i<=n;i++){
		string s;
		cin>>a[i]>>s;
		for(int j=1;j<=a[i];j++){
			c+=s;
		}
	}
	string h=c;
	reverse(h.begin(),h.end());
	for(int i=0;i<c.size();i++){
		if(h[i]!=c[i]){
			sum++;
		}
	}
	cout<<sum/2;
	return 0;
}