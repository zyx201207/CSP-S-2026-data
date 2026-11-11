#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k[210],flag=1;
long long m,a[500010]; 
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		cout<<1;
		if(a[i]+100>200||a[i]+100<0){
			flag=0;
//			cout<<1;
		}
	}
//	cout<<1;
	if(n<=5000){
		int maxn=0;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			int t=m;
			int cnt=0;
			for(int j=i;j>=1;j--){
				t-=(a[i]-a[j]);
				if(t<0)
					break;
				cnt++;
			}
			maxn=max(maxn,cnt);
		}	
		cout<<maxn;
		return 0;
	}
	
	if(flag==1){
//		cout<<1;
		for(int i=1;i<=n;i++){
			a[i]+=101; 
			k[a[i]]++;
		}
		int maxn=0;
		for(int i=1;i<=201;i++){
//			cout<<1;
			int t=m;
			int cnt=0;
			int f=0;
			for(int j=i;j>=1;j--){
//				cout<<1;
				if(k[j]*(i-j)<=t){
					t-=k[j]*(i-j);
					cnt+=k[j];
				}
				else{
					cnt+=(t/(i-j));
					break;
				}
			}
			maxn=max(maxn,cnt); 
		}
		cout<<maxn;
		return 0;
	}
	
	int d=abs(a[3]-a[2]);
	m/=d;
	int ans;
	int bruh=sqrt(2*m);
	if((bruh+1)*(bruh+2)/2<=m)
	ans=m+1;
	else if((bruh+1)*bruh/2<=m)
	ans=m;
	else
	ans=m-1;
	cout<<ans;
	return 0;
	
} 
