#include<bits/stdc++.h>
using namespace std;
struct node{
	long long bian,now;
	char x;
}a[200005];
int cnt=0;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	int last=1;
	for(int i=1;i<=n;i++){
		int ai;
		char ci;
		scanf("%d %c",&ai,&ci);
		a[++cnt].bian=last,a[cnt].x=ci,a[cnt].now=a[cnt].bian;
		last+=ai;
	}
	a[++cnt].bian=last;
	long long sum=0;
	int i=1,j=n;
	while(i<j){
		if(a[i+1].bian-a[i].now>a[j+1].bian-a[j].now){
			if(a[i].x!=a[j].x)sum+=(a[j+1].bian-a[j].now);
			a[i].now+=(a[j+1].bian-a[j].now);
			j--;
		}
		else if(a[i+1].bian-a[i].now<a[j+1].bian-a[j].now){
			if(a[i].x!=a[j].x)sum+=(a[i+1].bian-a[i].now);
			a[j].now+=(a[i+1].bian-a[i].now);
			i++;
		}
		else{
			if(a[i].x!=a[j].x)sum+=(a[j+1].bian-a[j].now);
			a[i].now+=(a[j+1].bian-a[j].now);
			j--;
			i++;
		}
	}
	printf("%d\n",sum);
	return 0;
}