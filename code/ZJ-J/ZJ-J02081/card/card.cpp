#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
struct stu{
	int bb,wb;
}ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-1;i++){
		int s[500005]={0};
		for(int j=i;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[k]==a[j]&&s[j]!=1&&s[k]!=1){
					for(int l=j;l<=k-1;l++){
						s[l]=1;
					}
				}
			}
			ans[a[j]].wb=ans[a[j]].bb;
		}
		for(int j=i;j<=n;j++){
			if(s[j]==0&&ans[a[j]].bb==ans[a[j]].wb){
				ans[a[j]].bb++;
			}
		}
	}
	ans[a[n]].bb++;
	for(int i=1;i<=m;i++){
		cout<<ans[i].bb<<" ";
	}
	return 0;
}
