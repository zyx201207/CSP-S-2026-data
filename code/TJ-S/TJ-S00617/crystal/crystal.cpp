#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=5e3;
int n,a[N],s[N];
long long m;
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	
	if(n>M){
		int k=1,anss=1;
		while(m>=k){
			m-=k;
			k++;
			anss++;
			if(k==n){
				cout<<anss;
				return 0;
			}
		}
		cout<<anss;
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]+=s[i-1]+a[i];
	}
	for(int i=n;i>ans;i--){
		for(int j=i-ans;j>0;j--){
			if(((i-j)*a[i])-s[i-1]+s[j-1]<=m){
				ans=max(i-j+1,ans);
			}
		}
	}
	cout<<ans;
	return 0;
}
