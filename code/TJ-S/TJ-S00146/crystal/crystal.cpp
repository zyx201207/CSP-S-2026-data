#include<bits/stdc++.h>
using namespace std;
const int N=5*100000+5;
long long n,m,k,ans=1;
long long a[N],tong[N];
void s1(long long d){
	long long i=1;
	for(long long j=i+1;j<=n;j++){
		if(m>=(j-i)*d){
			for(long long z=1;z<j;z++){
				a[z]=a[j];
			}
			m=m-(j-i)*d;
			ans++;
		}
		else{
			break;
		}
	}
	cout<<ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	long long pos,cishu=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tong[a[i]]++;
		if(tong[a[i]]>cishu){
			pos=i;
			cishu=tong[a[i]];
		}
	}
	sort(a+1,a+1+n);
	long long d=a[2]-a[1];
	if(d==a[3]-a[2]&&d==a[n]-a[n-1]&&d==a[2]-a[1]){
		s1(d);
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(m>=a[i+1]-a[i]){
			bool flag=true;
			for(int z=1;z<=i;z++){
				if(m>=a[i+1]-a[i]){
					m-=a[i+1]-a[z];
					a[z]=a[i+1];
				}
				else{
					flag=false;
					break;
				}
			}
			if(flag){
				ans++;
			}
		}
		else{
			break; 
		}
	}
	cout<<ans;
	return 0;
}
