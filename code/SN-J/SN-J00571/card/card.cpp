#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[300010],b[500010];
bool w[300010];
bool flag=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			flag=1;
		}
		ans[a[i]]=i;
	}
	if(!flag){
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
		return 0;
	}
	memset(ans,0,sizeof ans); 
	int sum=0;
	for(int k=1;k<=n;k++){
		memset(w,0,sizeof w);
		if(a[k]==a[k-1]){
			for(int i=1;i<=sum;i++){
				if(!w[b[i]])ans[b[i]]++,w[b[i]]=1;
			}
		}
		sum=0;
		for(int i=k;i<=n;i++){
			bool flag=0;
			for(int j=1;j<=sum;j++){
				if(b[j]==a[i]){
					sum=j;
					flag=1;
					break;
				}
			}
			if(!flag)b[++sum]=a[i];
		}
		for(int i=1;i<=sum;i++){
			if(!w[b[i]])ans[b[i]]++,w[b[i]]=1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

