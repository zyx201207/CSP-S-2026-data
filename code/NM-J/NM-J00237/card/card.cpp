#include <bits/stdc++.h>
using namespace std;
int top,a[500010],b[300010],c[300010],ans[300010];
int n,m;
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	while(n){
		b[++top] = a[n];
		if(c[b[top]]){
//			printf("	1\n");
			for(int i = c[b[top]] + 1;i < top;i++)
				c[i] = 0;
			top = c[b[top]];
		}
		c[a[n]] = top;
		for(int i = 1;i <= top;i++)
			ans[b[i]]++;
/*
		printf("n%d\n",n);
		for(int i = 1;i <= top;i++)
			printf("%d ",b[i]);
		printf("\n");
		for(int i = 1;i <= m;i++)
			printf("%d ",c[i]);
		printf("\n");
		for(int i = 1;i <= m;i++)
			printf("%d ",ans[i]);
		printf("\n");
*/
		n--;
	}
	for(int i = 1;i <= m;i++)
		printf("%d ",ans[i]);
}







/*
少年不识愁滋味
爱上层楼
爱上层楼
为赋新词强说愁












os:好像上nm迷惑行为大赏不知有没有人做
我是否该在这里留下luogu uid?
不管了 I love oi
*/
