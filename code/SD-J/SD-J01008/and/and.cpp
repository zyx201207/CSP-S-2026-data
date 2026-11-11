#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],flag,cnt=1;
string s[N],ans,sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ans+='1';
	for(int i=1;i<=n;i++){
		while(a[i]!=0){
			s[i]+=(char)a[i]%2;
			a[i]/=2;
		}
		cout<<s[i];
	}
	if(m==1){
		cout<<a[n];
		return 0;
	}
	cout<<ans;
	return 0;
}
