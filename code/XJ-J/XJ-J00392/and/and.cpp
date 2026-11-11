#include<bits/stdc++.h>
using namespace std;
int n,m,a[2*10010],c[55],summ,maxn,aa[55],bb[55],z=0,x=0,cc=1,sum,maxnn;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		summ=a[1];
		for(int l=j+1;l<=j+m;l++){
			while(summ!=0){
				aa[++z]=summ%2;
				summ=summ/2;
			}
			while(a[l]!=0){
				bb[++x]=a[l]%2;
				a[l]=a[l]/2;
			}
			maxn=max(z,x);
			for(int k=1;k<=maxn;k++){
					if(aa[k]==1&&bb[k]==1){
						c[k]=1;
					}else{
						c[k]=0;
					}
			}
			//for(int i=1;i<=maxn;i++){
			//	cout<<c[i]<<" ";
			//}
			for(int i=1;i<=maxn;i++){
				sum+=c[i]*cc;
				cc=cc*2;
			}
			summ=sum;
			for(int i=1;i<=maxn;i++){
				aa[i]=0;
				bb[i]=0;
				c[i]=0;
				z=0,x=0,cc=0;
			}
		}
		maxnn=max(maxnn,summ);
	}
	cout<<maxnn;
}