#include<bits/stdc++.h>
#define maxn 500010
#define maxm 300010
using namespace std;
int n,m,ans[maxm];
int a[maxn];
int lst[maxm];
int stk[maxn];
int top;
bool f[maxm];
void solve(int st){
	top=0;
	memset(f,0,sizeof(f));
	memset(lst,0,sizeof(lst));
	for(int i=st;i<=n;i++){
		if(lst[a[i]]==0){
			stk[++top]=a[i];
			lst[a[i]]=top;
		}else{
			if(lst[a[i]]<=top&&stk[lst[a[i]]]==a[i]){
				top=lst[a[i]];
			}else{
				stk[++top]=a[i];
				lst[a[i]]=top;
			}
		}
		for(int y=1;y<=top;y++){
			//cout<<y<<" ";
			if(f[y])
				continue;
			f[y]=1;
			ans[y]++;
		}
		//cout<<endl;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		solve(i);
		//cout<<"----\n";
	}
	for(int i=1;i<=m;i++)
		printf("%d%c",ans[i]," \n"[i==m]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
