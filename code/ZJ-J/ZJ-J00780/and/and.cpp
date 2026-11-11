#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool mark[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)mark[i]=true;
	for(int i=30;i>=0;i--){
		int sum=0;
		for(int j=1;j<=n;j++){
			if(!mark[j])continue;
			if(a[j]&(1<<i))sum++;
		}
		if(sum>=m){
			for(int j=1;j<=n;j++){
				if(!mark[j])continue;
				if(!(a[j]&(1<<i)))mark[j]=false;
			}
		}
	}
	int ans=(1<<30)-1;
	for(int i=1;i<=n;i++){
		if(mark[i])ans&=a[i];
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}