#include<bits/stdc++.h>
#include<deque>
#include<vector> 
using namespace std;
long long n,m;
long long a[50010];
deque<long long>zz;
bool vis[30010]={false};
long long ans[30010]={0};
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				vis[a[j]]=true;
				zz.push_front(a[j]);
			}else{
				long long t=zz.begin();
				do{
					vis[zz.begin()]=false;
					zz.pop_front();
				}while(zz.begin()=t);
				vis[a[j]]=true;
				zz.push_front(a[j]);
			}
		}
		for(int j=1;j<=n;j++){
			if(vis[j]){
				ans[j]++;
			}
		}
		for(int l=1;l<=m;l++){
			vis[l]=false;
		}
		while(zz.empty()){
			zz.pop_front();
		}
	}
	for(int i=1;i<=m;i++){
		if(ans[i]==0)continue;
		else cout<<ans[i]<<" ";
	}
	return 0;
}//用不了vector,deque函数。 
