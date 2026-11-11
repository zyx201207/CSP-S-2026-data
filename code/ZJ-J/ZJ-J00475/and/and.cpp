#include<bits/stdc++.h>
using namespace std;
bitset<32> x[500050];
int n,m,ans,s[500050],st[500050],top,top1,a[500050];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);top=n;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		int a1=a[i];
		for(int j=30;j>=0;j--){
			if(a1>=(1<<j)){
				a1-=(1<<j);
				x[i][j]=1;
			}
		}
	}for(int i=1;i<=top;i++) s[i]=i;
	for(int i=30;i>=0;i--){
		int cnt=0;top1=0;
		for(int j=1;j<=top;j++)
			if(x[s[j]][i]) st[++top1]=s[j],cnt++;
		if(cnt>=m){
			ans+=(1<<i);
			for(int i=1;i<=top1;i++)
				s[i]=st[i];
			top=top1;
		}
	}printf("%d ",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
