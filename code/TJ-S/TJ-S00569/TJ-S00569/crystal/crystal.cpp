#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	double a[1000010];
	double cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt+=a[i];
	}
	sort(a+1,a+1+n);
	cnt/=m;
	double s;
	for(int i=1;i<=n;i++){
		double t=min(t,a[i]-cnt);
		s=min(t-a[i],s);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=s){
			m-=s-a[i];
			a[i]=s;
		}
		for(int i=1;i<=n;i++){
			if(a[i]==s){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
