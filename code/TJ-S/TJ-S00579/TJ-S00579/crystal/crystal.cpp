#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
int a[500005];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		int k=m,sum=0;
		for(int j=i+1;j<=n;j++){
			if(k-a[i]+a[j]>=0){
				sum++;
				k=k-a[i]+a[j];
			}else{
				break;
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans+1;
	return 0;
}

