#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],c[510],ans[210],cc[100010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(n<=500&&m<=200){	
		for(int i=1;i<=n;i++){
			int l=0;
			for(int j=i;j<=n;j++){
				bool t=false;
				for(int k=l;k>=1;k--)
				    if(c[k]==a[j])
				        l=k,t=true;
				if(t==false)
				    c[++l]=a[j];
			}
			for(int j=1;j<=l;j++)
			    ans[c[j]]++;
		}
		for(int i=1;i<=m;i++)
		    printf("%d ",ans[i]);
		return 0;
	}
	for(int i=n;i>=1;i--)
	    cc[a[i]]++;
	for(int i=1;i<=n;i++)
		if(a[i]!=a[i-1])
		    printf("%d ",i+cc[a[i]]-1);
	return 0;   
}
