#include<cstdio>
#include<algorithm>
int n,m;
int a[500012];
int ans[300012];
bool has[300012];
int b[500012];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int t=1;t<=n;t++){
		ans[0]=0;
		for(int i=1;i<=n;i++)b[i]=0;
		for(int i=1;i<=m;i++)has[i]=false;
		int tail=0;
		for(int i=t;i<=n;i++){
			if(!has[a[i]]){
				has[a[i]]=true;
			}else{
				for(int j=i-1;;j--){
					if(!b[j])continue;
					if(b[j]==a[i]){
						b[j]=0;
						break;
					}
					has[b[j]]=false;
					b[j]=0;
				}
			}
			b[++tail]=a[i];
		}
		//for(int i=1;i<=tail;i++)printf("%d",b[i]);
		//puts("");
		for(int i=1;i<=tail;i++)ans[b[i]]++;
	}
	for(int i=1;i<=m;i++)printf("%d%c",ans[i]," \n"[i==n]);
	return 0;
}
