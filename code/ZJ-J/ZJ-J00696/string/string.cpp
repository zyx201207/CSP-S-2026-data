#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int cnt[N];
char a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>cnt[i]>>a[i];
	}
	int l=1,r=n;
	long long sum=0;
	while(l<r){
		int mi=min(cnt[l],cnt[r]);
		if(a[l]!=a[r]){
			sum+=mi;
		}
		cnt[l]-=mi;
		cnt[r]-=mi;
		if(cnt[l]==0) l++;
		if(cnt[r]==0) r--;
	}
	cout<<sum;
	return 0;
} 


