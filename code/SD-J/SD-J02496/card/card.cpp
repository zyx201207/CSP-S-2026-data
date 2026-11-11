#include<bits/stdc++.h>
using namespace std;
int n,m;
bool f[300010];
int a[200010];
int ans[300010];
stack<int>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	bool flg=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans[i]++;
		if(a[i]<a[i-1])
		{
			flg=0;
		}
	}
	if(flg){
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
		return 0;
	}//ÌØÊâÐÔÖÊA 
	for(int i=1;i<=m;i++){
		ans[i]=0;
	}
	for(int i=1;i<=n;i++){
		//cout<<1<<endl;
		for(int j=1;j<=m;j++){
			f[j]=0;
		}
		for(int s=i;s<=n;s++){
			if(f[a[s]]){
				while(q.top()!=a[s])
				{
					f[q.top()]=0;
					q.pop();
				}
			}
			else{
				f[a[s]]=1;
			q.push(a[s]);
			}
			
		}
		for(int k=1;k<=m;k++){
			if(f[k]){
				ans[k]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		//cout<<1<<endl;
		cout<<ans[i]<<" ";
	}
	return 0;
} 
