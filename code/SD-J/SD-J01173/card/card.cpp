#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],cnt[300010],l,s[300010];
bool f[300010]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		l=i;
		for(int j=1;j<=n;j++){
			f[j]=0;
			s[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(f[a[j]]!=0){
				l=j;
				for(int k=s[a[j]];k<=j;k++){
					f[a[k]]=0;
				}
			}
			s[a[j]]=j;
			f[a[j]]=1;
		}
		for(int j=1;j<=m;j++){
			if(f[j]==1){
				cnt[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}

