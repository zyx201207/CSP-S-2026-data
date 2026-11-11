#include<bits/stdc++.h>
using namespace std;
int n,m,num[500005],ans=0;
int cmp(int a,int b){
	return a<b;
}
int s(int l,int r,int su){
	for(int i=l;i<=r;i++){
		su+=num[i];
	}
	return su;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	sort(num,num+n+1,cmp);
	for(int i=1;i<=n;i++){
		int sum=m;
		for(int j=i+1;j<=n;j++){
			sum=s(i,j,sum);
			if(sum%(j-i+1)==0&&(sum/(j-i+1))==num[j]){
				ans=max(ans,j-i+1);
			}
		}
	}
	cout<<ans;
	return 0;
}
