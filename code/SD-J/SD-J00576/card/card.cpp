#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int a[500005],stack[200005],idx=0,flag[500005],sum;
int tong[300005],ans[300005];
int sum2[500005];
void fun(int x){
	memset(tong,0,sizeof(tong));
	memset(stack,0,sizeof(stack));
	for(int i=x;i<=n;i++){
		if(tong[a[i]]==1){
			while(1){
				if(stack[idx]==a[i]){
					stack[idx]=0;
					break;
				}
				stack[idx]=0;
				idx--;
			}
			idx--;
			tong[a[i]]=0;
		}
		stack[++idx]=a[i];
		tong[a[i]]=1;
	}
	for(int i=0;i<=idx;i++){
		ans[stack[i]]+=sum2[a[x]];
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum2[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		if(sum==m){
			break;
		}
		if(flag[a[i]]==0){
			fun(i);
			sum++;
		}
		flag[a[i]]=1;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
