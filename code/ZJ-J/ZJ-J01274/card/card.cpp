#include<bits/stdc++.h>
using namespace std;
int n,m,a[5005],ans[3005],num[5005],l=1;
int lst[5005];
bool vis[5005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		l=1;
		memset(vis,0,sizeof vis);
		memset(num,0,sizeof num);
		memset(lst,0,sizeof lst);
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				num[l]=a[j];
				l++;
				vis[a[j]]=1;
				lst[a[j]]=l-1;
			}
			else{
				for(int k=lst[a[j]]+1;k<l;k++){
					lst[num[k]]=0;
					vis[num[k]]=0;
					num[k]=0;
				}
				l=lst[a[j]]+1;
			}
		}
		for(int j=1;j<l;j++){
			ans[num[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}cout<<endl;
	return 0;
}
