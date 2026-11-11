#include<bits/stdc++.h>
using namespace std;
bool first;
const int N=600011;
long long n,m;
long long a[N],b[N];
long long qzh[N];
bool flag;
long long d;
bool xzAB=true;
void AB(){
	int sum=0;
	int jian=d;
	if(d==0){
		cout<<n;
		return;
	}
	for(int i=n;i>=1;i--){
		if(m<jian)break;
		m-=jian;
		jian+=d;
		sum++;
	}
	cout<<sum;
}
bool second;
int main() {
	//cerr<<(&second-&first)/1024/1024;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		long long x;
		cin>>x;
		a[i]=x;
		b[i]=a[i];
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	for(int i=2;i<=n;i++){
		if(i==2&&xzAB){
			d=a[2]-a[1];
		}else if(i>2&&xzAB){
			if(d!=a[i]-a[i-1]){
				xzAB=false;
				break;
			}
		}
	}
	if(xzAB){
		AB();
		return 0;
	}
	if(b[1]<0){
		for(int i=2;i<=n;i++){
			b[i]=b[i]-b[1];
		}
		b[1]=0;
	}
	long long ans=1;
	for(long long i=2;i<=n;i++){
		long long m2=m;
		long long sum=0;
		for(long long x=i;x>=1;x--){
			m2-=b[i]-b[x];
			if(m2<0){
				break;
			}
			sum++;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}

