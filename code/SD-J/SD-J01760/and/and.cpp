#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a;
long long sum[200005][35];
long long ans;
bool book[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a;
		string s="";
		while(a){
			s+=(a%2+'0');
			a/=2;
		}
		for(int j=0;j<s.size();j++){
			sum[i][j]=s[j]-'0';
		}
		long long k=s.size();
		maxn=max(maxn,k);
	}
	for(int i=maxn-1;i>=0;i--){
		long long k=0;
		for(int j=1;j<=n;j++){
			if(book[j]==true){
				continue;
			}
			if(sum[j][i]==1){
				k++;
			}
		}
		if(k>=m){
			ans+=(1ll<<i);
			for(int j=1;j<=n;j++){
				if(book[j]==true){
					continue;
				}
				if(sum[j][i]==0){
					book[j]=true;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

