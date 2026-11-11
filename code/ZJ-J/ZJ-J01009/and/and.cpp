#include<bits/stdc++.h>
using namespace std;
int n,m;
long long mx=0,lar,ana=0,a[200005],b[200005];
void dfs2(int x){  //x:已选择数的个数
	long long an=0;
	if (x==m){
		return ;
	}
		for (int i=1;i<=n-1;i++){
			for (int j=i+1;j<=n;j++){
				an=a[i]&a[j];
				if (an>mx){
					cout<<an<<' '<<a[i]<<' '<<a[j]<<'\n';
					mx=an;
					a[i]=an;
					a[j]=0;
				}
			}
		}
	dfs2(x+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		lar=max(lar,a[i]);
		b[i]=a[i];
	}
	if (m==1){
		cout<<lar;
		return 0;
	}
	if (m==n){
		for (int i=1;i<=n-1;i++){
			ana=a[i]&a[i+1];
			a[i+1]=ana;
		}
		cout<<ana;
		return 0;
	}
	dfs2(1);
	cout<<mx;
	return 0;
}