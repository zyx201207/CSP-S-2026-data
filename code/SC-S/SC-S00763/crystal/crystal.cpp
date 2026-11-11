#include<bits/stdc++.h>
using namespace std;
int n,anns[500005];
long long m,a[500005],b[500005],ans;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d",&n);
	cin>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
				b[j]=a[i]-a[j];
		}
		sort(b+1,b+n+1);
		int g=m;
		for(int j=1;j<=n;j++){
			if(g>=b[j]){
			    if(b[j]>=0){
			   		g-=b[j];
					anns[i]++;
				}		
			}
			else break;
		}
	}
	for(int i=1;i<=n;i++){
		if(anns[i]>ans)
			ans=anns[i];
	}
	printf("%d",ans);
	return 0;
}