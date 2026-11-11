#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m;
int a[N];
int ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(m==1){
		cout<<n;return 0;
	}//hhhhh
	bool fl=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];if(a[i]<a[i-1]){fl=0;
		}
	}
	if(fl){
		for(int i=1;i<=n-1;i++){
			if(a[i+1]!=a[i]){
				ans[a[i]]=i;
			}
		}
		ans[a[n]]=n;
	}else{
		for(int i=1;i<=n;i++){
		int q[N]={0};
		int num[N]={0};
		int p=0;
		for(int j=i;j<=n;j++){
			if(!num[a[j]]){
				q[++p] = a[j];
				num[a[j]]=p;
			}else{
				for(int k=num[a[j]]+1;k<=p;k++){
					num[q[k]]=0;
				}
				p=num[a[j]];
			}
		}
		for(int j=1;j<=p;j++){
			ans[q[j]]++;
		}
	}
	}
	
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
