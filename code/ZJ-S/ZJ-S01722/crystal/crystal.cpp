#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans=0;
long long a[600005];
long long pre[600005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool flag1=false;
	bool flag2=false;
	long long cnt=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	int kk=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=kk) flag2=true;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]!=i) flag1=true;
	}
	if(flag1==false){
		if(m>n) cout<<n;
		else cout<<m+1;
	}
	else if(flag2==false){
		if(m/kk>n) cout<<n;
		else cout<<m/kk+1;
	}
	else{
		sort(a+1,a+n+1);
		pre[1]=a[1];
		for(int i=2;i<=n;i++) pre[i]=pre[i-1]+a[i];
		for(int i=n;i>=2;i--){
			long long cnt=0;
			int j=i-1;
			int m1=m;
			if(pre[i]-pre[i-ans-1]+m<=a[i]*ans) continue;
			while(true){
				if(j==0) break;
				if(m1>=(a[i]-a[j])){
					m1-=a[i];
					m1+=a[j];
					cnt++;
					j--;
				}
				else break;
			}
			ans=max(ans,cnt+1);
			//cout<<cnt+1<<" ";
		}
		cout<<ans;
	}
	return 0;
}
