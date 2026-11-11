#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],cnt[300005],d[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(d[a[j]]==0) d[a[j]]=j;
			else{
				for(int k=d[a[j]];k<j;k++){
					d[a[k]]=0;
				}
				d[a[j]]=j;
			}
		}
		for(int j=1;j<=n;j++){
			if(d[a[j]]!=0){
				cnt[a[j]]++;
				d[a[j]]=0;
			} 
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
} 
