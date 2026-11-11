#include<bits/stdc++.h>
using namespace std;
long long n,a[500010],t,cha,m,ans;
bool te;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	sort(a+1,a+n+1);
	te=true;
	cha=a[2]-a[1];
	for(int i=2;i<n;i++){
		if(a[i+1]-a[i]!=cha)te=false;
	}
	if(te){
		for(int i=n;i>=1;i--){
			m-=a[n]-a[i];
			if(m>=0)ans++;
		}
		cout<<ans;
	}
	else {
		long long maxans=1,m1;
		for(int i=1;i<=n;i++){
			if(a[i]==a[i+1]&&i!=n)continue;
			ans=1;m1=m;
			for(int j=i-1;j>0;j--){
				m1-=a[i]-a[j];
				if(m1>=0)ans++;
			}
			maxans=max(maxans,ans);
		}
		cout<<maxans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
