#include<bits/stdc++.h>
using namespace std;
//李源东 SN-S00370  西安市第三中学 
int a[500001]={0};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,num=0,maxx=-1,c=1,d=1,k;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=a[i]){
			c=0;
		}
		if(i==2){
			k=a[i]-a[i-1];
		}
		if(i>2&&a[i]-a[i-1]!=k){
			d=0;
		}
	}
	if(c==1){
		for(int i=1;i<=n;i++){
			num+=i-1;
			if(num==m){
				maxx=i;
				break;
			}else if(num>m){
				maxx=i-1;
				break;
			}else if(i==n&&num<m){
				maxx=i;
			}
		}
		cout<<maxx;
	}else if(c==0&&d==1){
		for(int i=1;i<=n;i++){
			num+=(i-1)*k;
			if(num==m){
				maxx=i;
				break;
			}else if(num>m){
				maxx=i-1;
				break;
			}else if(i==n&&num<m){
				maxx=i;
			}
		}
		cout<<maxx;
	}else{
		sort(a+1,a+n+1);
		for(long long i=n;i>=1;i--){
			if(i<=maxx){
				break;
			}
			long long b=m;
			num=1;
			for(int j=i-1;j>=1;j--){
				if(num+j<=maxx){
					break;
				}
				if(b>=a[i]-a[j]){
					b-=(a[i]-a[j]);
					num++;
				}else{
					break;
				}
				maxx=max(maxx,num);
			}
		}
		cout<<maxx;
	}
	
}
