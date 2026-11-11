#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],num[300010],p[300010],st[500010],ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			num[j]=0;
			p[j]=0;
		}
		for(int j=1;j<=n;j++) st[j]=0;
		for(int j=i;j<=n;j++){
			num[a[j]]++;
			if(num[a[j]]>1){
				for(int l=p[a[j]];l<j;l++){
					if(!st[l]){
						num[a[l]]--;
						st[l]=1;
					}
				}
			}
			p[a[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(num[j]) ans[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

