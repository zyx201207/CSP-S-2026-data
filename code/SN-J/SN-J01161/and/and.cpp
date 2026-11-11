#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[32];
long long b[20005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>k; 
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	sort(b+1,b+n+1);
	long long w=b[n];
	long long maxn=-1;
	for(int i=2;i<=n;i++){
		if(b[i-1]==b[i]){
			maxn=max(maxn,b[i]);
		}
	}
	for(int i=n;i>=n-k+1;i--){
		w=w&(b[i]);
	}
	if(k==2){
		long long maxn=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				}else{
					maxn=max(maxn,b[i]&(b[j]));
				}
			}
		}
		cout<<maxn<<endl;
	}
	cout<<w;
	return 0;
} 
