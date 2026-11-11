#include<bits/stdc++.h>
using namespace std;
int res[200005][32];
unsigned int num[32];
int cnt[32];
bool unselected[200005];
bool cmp(unsigned int a,unsigned int b){
	return a>=b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	num[0]=1;
	for(int i=1;i<32;i++){
		num[i]=num[i-1]*2;
	}
	int n,m;
	cin>>n>>m;
	unsigned int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		unsigned int b=a[i];
		for(int j=0;j<32;j++){
			res[i][j]=b%2;
			b/=2;
			if(res[i][j]==1)cnt[j]++;
		}
	}
	unsigned int ans=0;
	for(int l=31;l>=0;l--){
		if(cnt[l]<m){
			continue;
		}
		ans+=num[l];
		for(int i=0;i<n;i++){
			if(unselected[i])continue;
			if(res[i][l]==0){
				unselected[i]=1;
				for(int j=0;j<l;j++){
					if(res[i][j]==1)cnt[j]--;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
