#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,ans,mn=-1,x,y,h,z;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	ans=a[1];
	if(m==n){
		for(int i=2;i<=m;i++)
			ans&=a[i];
		cout<<ans;
		return 0;
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				mn=max(a[i]&a[j],mn);
			}
		}
		cout<<mn;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(i==1){
					mn=max(a[j]&a[k],mn);
					z=a[j]&a[k];
					if(z>=mn)
						x=a[j],y=a[k];
				}
				else{
					mn=-1;
					if(a[k]!=x&&a[k]!=y)
						mn=max(h&a[k],mn);
				}
			}
		}
		h=mn;
	}
	cout<<h;
	return 0;
}


