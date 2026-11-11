#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int>a;
	a.push_back(0);
	for(int i=0;i<n;i++){
		int c;
		cin>>c;
		a.push_back(c);
	}
	int h[300005]={0};
	vector<int> ans(m+1);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++)h[j]=0;
		for(int j=i;j<=n;j++){
			if(h[a[j]]!=0) {
				for(int k=h[a[j]];k<j;k++){
					if(h[a[k]]==k)h[a[k]]=0;
				}
			}
			h[a[j]]=j;
		}
		for(int j=0;j<=m;j++)if(h[j]!=0)ans[j]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
