#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,a[500005],b[500005],maxn=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int flag=1;
	long long p=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i+1]-a[i]!=p){
			flag=0;
			break;
		}
	}
	if(flag==0){
		for(int i=2;i<=n;i++){
			long long c=0,cnt=0;
			for(int j=1;j<=i;j++){
				b[j]=a[i]-a[j];
			}
			sort(b+1,b+i+1);
			for(int j=1;j<=i;j++){
				if(b[j]+c<=m){
					c+=b[j];
					cnt++;
				}
			}
			maxn=max(maxn,cnt);
		}
	}
	if(flag==1){
		long long x=a[2]-a[1];
		long long cnt=0,k=1;
		while(1){
			cnt+=k*x;
			k++;
			if(cnt>m){
				break;
			}
			maxn++;
		}
	}
	cout<<maxn;
	return 0;
} 
