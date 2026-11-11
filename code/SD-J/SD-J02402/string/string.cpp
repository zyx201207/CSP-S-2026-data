#include<bits/stdc++.h>
const int N=2e5+5;
using namespace std;
int n,a[N],sum=0,gs=0;
string s;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(int j=0;j<a[i];j++){
			s=s+c[i];
			gs++;
		}
	}
	for(int i=0;i<gs/2;i++){
		if(s[i]!=s[n-i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
