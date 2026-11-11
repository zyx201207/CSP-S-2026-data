#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1,M=3e5+1;
int n,m,f;
bool flag;
int a[N],cnt[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.ont","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		f=i-1;
		for(int j=i;j<=n/2;j++){
			for(int k=n;k>j;k--){
				if(a[j]==a[k]){
					f=k-1;
					flag=1;
					break;
				}
			}
			if(flag==1){
				flag=0;
				break;
			}
		}
		for(int j=f+1;j<=n;j++){
			cnt[a[j]]++;
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
