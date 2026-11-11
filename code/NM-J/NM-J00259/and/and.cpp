#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],mx=-1;
void AND(int x,int y,int ans){
	if(x==0){
		mx=max(mx,ans);
		return ;
	}
	for(int i=y+1;i<=n;i++){
		ans=ans&a[i];
		AND(x-1,i,ans);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]!=-1){
			for(int j=i+1;a[j]<=a[i]&&j<=n;j++){
				if(a[i]==a[j])a[j]=-1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		AND(m-1,i,a[i]);
	}
	cout<<mx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
