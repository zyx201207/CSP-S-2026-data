#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+1e5;
const int M=1e3+1e2;
struct node{
	int a;
	char c;
}b[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	string s="";
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>b[i].a>>b[i].c;
	}
	int maxn=-1e18;
	for(int i=1;i<=n;i++){
		maxn=max(maxn,b[i].a);
	}
	if(maxn==1){
		if(n%2){
			cout<<n/2-1;
			return 0;
		}else{
			cout<<n/2;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=b[i].a;j++){
			s=s+b[i].c;
		}
	}
	bool flag=1;
	int m=s.size();
	for(int i=1;i<m;i++){
		if(s[i]!=s[i-1]){
			flag=0;
			break;
		}
	}
	if(flag==1){
		cout<<0;
		return 0;
	}
	int res=0;
	for(int i=m/2-1;i>=0;i--){
		if(s[i]!=s[m-i-1]){
			res++;
		}
	}
	cout<<res;
	return 0;
}
