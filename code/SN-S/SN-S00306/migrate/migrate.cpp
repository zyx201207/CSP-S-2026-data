#include<bits/stdc++.h>
using namespace std;
int c,t;
long long a[5010];
int ki[5010],flag[5010];
unsigned long long ans,L;
void f(int x,int y,int l,vector<long long>k[]){
	if (x==y){
		if (l<L || L==0){
			L=l;
			ans=1;
		}else if (l==L){
			ans++;
		}
		return;
	}
	for (int i=0;i<ki[x];i++){
		if (flag[k[x][i]]==0){
			flag[k[x][i]]=1;
			f(k[x][i],y,l+1,k);
			flag[k[x][i]]=0;
		}
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while (t--){
		int n;
		unsigned long long d,num=0;
		vector<long long>k[5010];
		scanf("%d%llu",&n,&d);
		for (int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			ki[i]=0;
			for (int j=i-1;j>=1;j--){
				if (a[i]-a[j]<=d){
					k[i].push_back(j);
					k[j].push_back(i);
					ki[i]++;
					ki[j]++;
				}else{
					break;
				}
			}
		}
		for (int i=1;i<n;i++){
			for (int j=i+1;j<=n;j++){
				if (i==j){
					continue;
				}
				memset(flag,0,sizeof(flag));
				ans=0,L=0;
				flag[i]=1;
				f(i,j,0,k);
				flag[i]=0;
				if (ans==2){
					num++;
				}
			}
		}
		printf("%llu\n",num);
	}
	return 0;
}
