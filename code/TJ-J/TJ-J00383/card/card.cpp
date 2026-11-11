#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	vector<int> ans(m+5);
	for(int i=1;i<=n;i++){
		int t[500005]={0};
		int size=0;
		for(int j=i;j<=n;j++){
			int x=-1;
			for(int k=1;k<=size;k++){
				if(t[k]==a[j]){
					x=k;
					break;
				}
			}
			if(x==-1){
				t[++size]=a[j];
			}else{
				size=x-1;
				t[++size]=a[j];
			}
		}
		for(int j=1;j<=size;j++){
			ans[t[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
