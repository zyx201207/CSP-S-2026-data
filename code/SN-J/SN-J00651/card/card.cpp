//马知遥 西安交通大学附属中学 SN-J00651 
#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000005],pre[1000005],ans[1000005],mx[1000005];
struct node{
	int x,y;
}jump[1000005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	bool flag=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>a[i+1]){
			flag=1;
		}
		pre[a[i]]++;
		mx[a[i]]=max(i,mx[a[i]]);
	}
	if(flag){
		set<int>se;
		for(int i=1;i<=n;i++){
			int mxx=i;
			for(int j=i;j<=n;j++){
				if(mx[a[j]]!=j){
					j=mx[a[j]];
					mxx=j;
				}
			}
	//		cout<<"the mx:"<<mxx<<"\n";
			for(int j=mxx;j<=n;j++){
				se.insert(a[j]);
			}
			for(int w:se){
				ans[w]++;
			}
			se.clear();
		}
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=n;j>i;j--){
				ans[a[j]]++;
				if(a[j]==a[j-1]){
					break;
				}
			} 
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}
//每次向后跳，O(n) 
