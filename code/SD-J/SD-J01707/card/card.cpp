#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans[300005],a[500005];
long long cnt,s[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	int f=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]<a[i-1]) f=1;
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	if(f==0){
		for(int i=1;i<=n;i++){
			cnt=0;
			for(int j=i;j<=n;j++){
				if(a[j]==a[j-1]&&i!=j){
					continue;
				}
				s[++cnt]=a[j];
			}
			bool f[300005];
			memset(f,0,sizeof(f));
			for(int i=1;i<=cnt;i++){
				if(f[s[i]]==0){
					f[s[i]]=1;
					ans[s[i]]++;
				}
			}
		}
		for(int i=1;i<=m;i++){
			printf("%d ",ans[i]); 
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		cnt=0;
		for(int j=i;j<=n;j++){
			int l=1,r=cnt;
			while(l<=r){
				if(l==a[j]){
					cnt=l;
				} 
				if(r==a[j]){
					cnt=r;
				}
				l++;
				r--;
			}
			s[++cnt]=a[j];
		}
		bool f[300005];
		memset(f,0,sizeof(f));
		for(int i=1;i<=cnt;i++){
			if(f[s[i]]==0){
				f[s[i]]=1;
				ans[s[i]]++;
			}
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
