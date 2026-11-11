#include<iostream>
#include<cstring>
using namespace std;
int n,m,a[500005],l[300005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(l,0,sizeof(l));
		for(int j=i;j<=n;j++){
			if(l[a[j]]!=0){
				for(int k=l[a[j]];k<=j;k++){
					l[a[k]]=0;
				}
			}
			l[a[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(l[j]){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
//csp 2026 rp+
/*
CCF老师，我会记得你
估分：100+62+100+44=306
稳吗？1=
第一次打复赛，就那么顺利
前途无li-yang
*/
