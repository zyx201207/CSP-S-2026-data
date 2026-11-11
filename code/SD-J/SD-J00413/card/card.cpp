#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ne[500005];//ne[i]下一个a[i]出现的位置 
int la[300005];//la[i]:上一个i出现的位置 
int ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(la[a[i]]==0){//第一个a[i] 
			la[a[i]]=i;
		}else{//不是第一个a[i] 
			ne[la[a[i]]]=i;
			la[a[i]]=i;
		}
//		for(int i=1;i<=n;i++){
//			cout<<ne[i]<<" ";
//		}
//		cout<<endl;
	}
//	for(int i=1;i<=n;i++){
//		cout<<ne[i]<<" ";
//	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(ne[j]!=0){
				j=ne[j]-1;
			}else{
				ans[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
