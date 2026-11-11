#include <bits/stdc++.h>
using namespace std; 
char b[20005][20005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[20005];
	int ans[20005],cnt[20005];
	int j;
	for(int i=0;i<n;i++){
		cin>>a[i];
		while(a[i]>=1){
			b[i][j]=a[i]%2;
			j++;
		}
	}
	for(int i=0;i<n;i++){
		for(j=0;j<n-1;j++){
			if(b[i][j]==b[i][j+1]){
				ans[i]++;
			}
		}
	}
	sort(ans,ans+n);
	int k=0;
	for(int i=0;i<n;i++){
		for(;k<n;k++){
			if(ans[k]!=ans[k+1]){
				break;
			}
			cnt[i]++;
		}
		if(cnt[i]==m){
			cout<<cnt[i];
			return 0;
		}
	}
	return 0;
}
