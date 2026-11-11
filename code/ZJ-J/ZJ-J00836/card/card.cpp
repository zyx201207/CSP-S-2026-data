#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200100];
int cnt[5004];
int f[5004];
int res[5004];
int t[5004];
int main (){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(cnt,0,sizeof(cnt));
		memset(f,0,sizeof(f));
		memset(t,0,sizeof(t));
		int last=-1;
		for(int j=i;j<=n;j++){
			if(cnt[a[j]]!=0){
				int st=j-1;
				if(last!=-1){
					st=last;
				}
				for(int k=j-1;k>=i;k--){
					if(f[k]==1)continue;
					f[k]=1;
					cnt[a[k]]--;
					if(a[k]==a[j]){
						last=k;
						break;
					}
				}
			}
			cnt[a[j]]++;
		}
		for(int j=i;j<=n;j++){
			if(f[j]==0){
				t[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			if(t[j]==1)res[j]++;
		}
	}
	for(int j=1;j<=m;j++){
		cout<<res[j]<<" ";
	}
	return 0;
}


