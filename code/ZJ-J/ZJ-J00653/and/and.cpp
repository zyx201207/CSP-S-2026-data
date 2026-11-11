#include<bits\stdc++.h>
using namespace std;
int a[200001],b[200001];
void nlogn(int l,int r){
	if(l>=r)return;
	int middle=(l+r)/2;
	nlogn(l,middle);
	nlogn(middle+1,r);
	int i=l,j=middle+1,k=l;
	while(k<=r){
		if(a[i]>=a[j]||j>r){
			b[k]=a[i];
			i++;
			k++;
		}
		if(a[i]<a[j]||i>middle){
			b[k]=a[j];
			j++;
			k++;
		}
	}
	for(int i=l;i<=r;i++)a[i]=b[i];
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	nlogn(1,n);
	int ans=0b11111111111111111111111111111111;
	for(int i=1;i<=m;i++)ans=ans&a[i];
	printf("%d",ans);
	return 0;
}
