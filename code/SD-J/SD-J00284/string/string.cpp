#include <bits/stdc++.h>
using namespace std;
int n;
int a[200010],b[200010];
char c[200010];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
		cin>>c[i];
	}	
	long long ans1=0,ans2=0;
	//long long tmp=0;
	int l=1,r=n;
	while(l<=r){
		long long tmp=a[l];
		 while(tmp){
		 	if(l==r&&a[l]<=2)break;
		 	if(c[l]==c[r]){
		 		if(tmp>=a[r])tmp-=a[r],a[l]-=a[r],a[r]=0;
		 		else a[r]-=tmp,a[l]=0,tmp=0;
		 		if(a[r]==0)r--;
		 		continue;
			}
		 	if(tmp>=a[r]){
		 		tmp-=a[r];
		 		a[l]-=a[r];
		 		ans1+=a[r];
		 		a[r]=0;
			 }else {
			 	a[r]-=tmp;
			 	a[l]=0;
			 	ans1+=tmp;
			 	tmp=0;
			 }
			 if(a[r]==0)r--;
		 }
		 l++;
	}

	cout<<ans1;
	return 0;
}
