#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005],d[500005],s[500005]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		d[i]=d[i-1]+(a[i]-a[i-1])*(i-1);
	}
	if(n<=10000){
		for(int len=n;len>=2;len--){
			for(int i=1;i+len-1<=n;i++){
				int j=i+len-1;
				bool f=0;
				long long sum=d[j]-d[i-1];
				if(sum<=m){
					cout<<len;
					return 0;
				}
			}
		}
		cout<<1;
	}
	else{
		sort(a+1,a+n+1);
		d[1]=0;
		for(int i=2;i<=n;i++){
			d[i]=a[i]-a[i-1];
		}
		long long maxx=1,sum=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(sum+d[i]*cnt>m){
				maxx=max(maxx,cnt);
				cnt=1;
			}
			else{
			sum=d[i]*cnt+sum;
			cnt++;	
			}
			
		}
		maxx=max(maxx,cnt);
		cout<<maxx;
	}
	
	return 0;
} 
