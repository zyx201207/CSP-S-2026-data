#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans[N],h[N];
bool B;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
	scanf("%d",&a[i]);
if(a[i]<a[i-1])B=1;
}
if(B==0){
	for(int i=1;i<=n;i++)ans[a[i]]=max(i,ans[a[i]]);
for(int i=1;i<=m;i++)
printf("%d ",ans[i]); 
}
else { 
for(int i=1;i<=n;i++)
h[a[i]]=i;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;){
			ans[a[j]]++;
			if(h[a[j]]!=j){j=h[a[j]];}
			j++;
		}
	}
	for(int i=1;i<=m;i++)
printf("%d ",ans[i]); 
}
	return 0;
} 
