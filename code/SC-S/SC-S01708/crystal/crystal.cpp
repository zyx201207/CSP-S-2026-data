#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,g=0,x=1;
	long long m,m1=0,ans=0,anse=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		g++;
		if(m1+g*(a[i+1]-a[i])<=m){
			m1+=g*(a[i+1]-a[i]);
			ans++;
		}
		else{
			int l=ans;
			while(m1+g*(a[i+1]-a[i])>m){
				m1-=a[i+1]-a[x];
				l--;
				x++;
				g--;
			}
			ans=l++;
		}
		anse=max(anse,ans);
	}
	anse+=1;
	cout<<anse;
	return 0;
}


