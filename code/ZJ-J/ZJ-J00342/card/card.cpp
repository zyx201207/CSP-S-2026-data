#include<iostream>
#include<vector>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>a(n+1,0);
	vector<int>ans(m+1,0);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		vector<int>pos(m+1,0);
		int now=0;
		for(int j=i;j<=n;j++){
			if(pos[a[j]]!=0){
				for(int k=1;k<=m;k++){
					if(pos[k]>pos[a[j]]){
						pos[k]=0;
					}
				}
				now=pos[a[j]];
			}else{
				pos[a[j]]=++now;
			}
		}
		for(int j=1;j<=m;j++){
			ans[j]+=(!!pos[j]);
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}
