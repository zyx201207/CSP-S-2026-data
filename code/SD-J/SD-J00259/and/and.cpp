#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int MAXN=2e5+5;
int n,m,ans,a[MAXN],cnt[MAXN];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",a+i); 
	if(n<=20){
		for(int i=1;i<=((1<<n)-1);i++){
			int sum=0,cnt=0;
			for(int j=1;j<=n;j++){
				if(((i>>(j-1))&1)==1){
					cnt++;
					if(!sum) sum=a[j];
					else sum=sum&a[j];
				}
			}
			if(cnt==m) ans=max(ans,sum);
		}
		printf("%d",ans);
	}
	else if(n<=2000){
		if(m==1){
			for(int i=1;i<=n;i++) ans=max(ans,a[i]);
			printf("%d",ans);
		}
		if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					ans=max(ans,a[i]&a[j]);
				}
			}
			printf("%d",ans); 
		}
		if(m==n){
			for(int i=1;i<=n;i++) ans=ans&a[i];
			printf("%d",ans); 
		}
	}
	else{
		for(int i=1;i<=n;i++){
			cnt[i]=log2(a[i])+1; 
		}
		sort(cnt+1,cnt+1+n);
		printf("%d",(1<<cnt[n-m+1])-1);
	}
	return 0;
}

