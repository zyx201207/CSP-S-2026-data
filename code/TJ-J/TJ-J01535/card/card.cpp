#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2000021],b[6000][4000],top,s[10000],b1[6000][4000],ans[10000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		top=0;
		for(int j=i;j<=n;j++){
			if(b1[i][a[j]]==0){
				s[++top]=a[j];
				b1[i][a[j]]=top;
				
			}
			else{
				top=b1[i][a[j]];
			}
		}	
		for(int j=1;j<=top;j++){
				ans[s[j]]++;		
		}
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",ans[i]);
	}
	return 0;
}
