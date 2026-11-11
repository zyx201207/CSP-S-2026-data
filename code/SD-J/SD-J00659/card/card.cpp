#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],f[500005],b[500005],cnt[300005],o=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			o=1;
		}
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	if(o==0){
		for(int i=1;i<=n;i++){
			int x=n-i+1;
			memset(f,0,sizeof f);
			memset(b,0,sizeof b);
			for(int j=i;j<=n;j++){
				b[a[j]]=1;
			}
			for(int j=1;j<=n;j++){
				if(b[a[j]]==1&&f[a[j]]==0){
					f[a[j]]=1;
					cnt[a[j]]++;
				}	
			}
		}
		for(int i=1;i<=m;i++){
			cout<<cnt[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof f);
		memset(b,0,sizeof b);
//		memset(s,0,sizeof s);
		for(int j=i;j<=n;j++){
			if(b[a[j]]!=0){
				for(int k=b[a[j]];k<=j;k++){
					b[a[k]]=0;	
				} 
			}
			b[a[j]]=j;	
		}
		for(int i=1;i<=n;i++){
			if(b[a[i]]!=0&&f[a[i]]==0){
				f[a[i]]=1;
				cnt[a[i]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
} 
