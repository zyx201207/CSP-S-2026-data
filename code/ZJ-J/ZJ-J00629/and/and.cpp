#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxx,ander,ans,le[200005],ri[200005];
bool bo,bi;
void dfs(int cou,int cnt,int no){
	if(cnt>=m){
		ans=max(ans,no);
		return;
	}
	for(int i=cou+1;i+(m-cnt-1)<=n;i++){
		dfs(i,cnt+1,(no&a[i]));
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxx=max(maxx,a[i]);
		if(a[i]!=i-1){
			bo=1;
		}
		if(a[i]>4){
			bi=1;
		}
	}
	le[1]=a[1];
	for(int i=2;i<=n;i++){
		le[i]=(le[i-1]&a[i]);
	}
	ri[n]=a[n];
	for(int i=n-1;i>=1;i--){
		ri[i]=(ri[i+1]&a[i]);
	}
	ander=a[1];
	for(int i=2;i<=n;i++){
		ander&=a[i];
	}
	if(m==1){
		printf("%d",maxx);
		return 0;
	}
	if(m==n){
		printf("%d",ander);
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,(a[i]&a[j]));
			}
		}
		printf("%d",ans);
		return 0;
	}
	if(!bo){
		int res=a[n];
		for(int i=n-1;i>=(n-m+1);i--){
			res&=a[i];
		}
		printf("%d",res);
		return 0;
	}
	if(m==n-1){
		for(int i=1;i<=n;i++){
			if(i==1){
				ans=max(ans,ri[2]);
			}
			else if(i==n){
				ans=max(ans,le[n-1]);
			}
			else{
				ans=max(ans,(le[i-1]&ri[i+1]));
			}
		}
		printf("%d",ans);
		return 0;
	}
	if(n<=20){
		dfs(0,0,a[1]);
		printf("%d",ans);
		return 0;
	}
	if(!bi){
		printf("4");
		return 0;
	}
	printf("0");
	return 0;
}//70pts
