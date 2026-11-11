#include<bits/stdc++.h>
using namespace std;
int max_bi;
int ej1s(int x){
	int y;
	while(x!=0){
		y+=x&1;
		x/=2;
	}
	return y;
}
int n,m,a[200001],bi[200001],ans;
vector<int>v;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		bi[i]=ej1s(a[i]);
	}
	sort(a+1,a+n+1);
	ans=a[1];
	for(int i=1;i<=m;i++)
		ans=ans&a[i];
	printf("%d",ans);
}
