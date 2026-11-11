#include<bits/stdc++.h>
using namespace std;
int n,m,l;
int a[500001];
int b[500001];
int sum[500001];
int main(){
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	l = n;
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		b[i] = a[i];
	}
	for(int i = 1;i <= l;i++){
		for(int j = 1;j <= l;j++){
			b[j] = a[j];
		}
		for(int j = i;j <= l;j++){
			int w = 0;
			for(int k = 1;k <= n;k++)
			    if(b[k] == a[j])
			       w = k;
			if(w){
			   for(int k = w + 1;k <= n;k++)
			   	   b[k] = 0;
			   n = w;
			}else{
			   n++;
			   b[n] = a[j];
			}
		}
		for(int j = 1;j <= n;j++)
		    sum[b[j]]++;
	}
	for(int i = 1;i <= m;i++)
	    printf("%d ",sum[i]);
	return 0;
}
