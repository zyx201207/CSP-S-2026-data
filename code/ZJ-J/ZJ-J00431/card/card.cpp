#include <bits/stdc++.h>
using namespace std;
int a[200200];
	int n,m;
int find(int num){
	int l=1,r=n,ans=0;
	while(l<=r){
		int mf=(l+r)/2;
		if(num>=a[mf]){
			if(num==a[mf])ans=mf;
			l=mf+1;
		}else r=mf-1;
	}
	return ans;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(m>2){
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=m;i++)cout<<find(i)<<" ";
	}else{
		int x=0,b=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			if(a[i]!=a[n])x++,b++;
			else{
				if(a[n]==1)x++;
				else b++;
			}
		}
		cout<<x<<" "<<b;
	}
	return 0;
}

