#include<cstdio>
using namespace std;
int a[500500];//顺序  
int last[300300];//最后一个的位置 
int next[300300];//a[last[i]+1]
int num[300300]={0};//元素个数 
int ans[300300]={0};//答案  
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		last[a[i]]=i;
		num[a[i]]++;
	}
	a[n]=-1;
	for(int i=1;i<=m;i++){
		next[i]=a[last[i]+1];
	}
	for(int i=1;i<=m;i++){
		for(int j=i;j!=-1;j=next[j]){
			ans[j]+=num[i];
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
/*
if(a[i]==i)ans++;
if(i>m)continue;
*/
