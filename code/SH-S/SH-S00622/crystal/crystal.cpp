#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[500001],ans;
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	if(n==1)cout<<0;
	else if(n<=5000){
		for(int i=2;i<=n;i++){
			int cnt=0,sum=0;
			for(int j=i-1;j>=1;j--){
				cnt+=(a[i]-a[j]);
				sum++;
				if(cnt>m)break;
			}
			if(cnt>m)sum--;
			ans=max(ans,sum);
		}
		if(ans==0)cout<<0;
		else cout<<ans+1;
	}
	else{
		int b=a[2]-a[1],c=max(a[1],a[n]),d=abs(a[1]-a[n]);
		int e=n*(n-1)/2*b;
		if(m>=e)cout<<n;
		else{
			for(int i=2;i<=n;i++){
				int f=i*(i-1)/2*b;
				if(m<f&&i==2){
					cout<<0;
					return 0;
				}
				else if(m<f){
					cout<<i;
					return 0;
				}
			}
		}
	}
	return 0;
} 
