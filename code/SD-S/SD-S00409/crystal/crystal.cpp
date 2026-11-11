//75pts  Hzy2024

//1   14:48  1~9 45pts  o(n^2)
/*#include <iostream>
#include <algorithm>
using namespace std;
const long long N=510000;
long long n,m;
long long a[N];
long long ans;
bool cmp(long long a,long long b){
	return a>b;
}
long long f(long long k){
	long long tm=m;
	long long cnt=0;
	for(long long i=k;i<=n;++i){
		if(tm>=a[k]-a[i]){
			tm-=a[k]-a[i];
			++cnt;
		}
		else{
			break;
		}
	}
	return cnt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(long long i=1;i<=n;++i){
		ans=max(ans,f(i));
	}
	cout<<ans<<endl;
	return 0;
}*/

//2    14:58 1~9+13~15+16~18 75pts o(n^2)+A+B
/*#include <iostream>
#include <algorithm>
using namespace std;
const long long N=510000;
long long n,m;
long long a[N];
long long ans;
bool A=1;
long long at;
bool cmp(long long a,long long b){
	return a>b;
}
long long f(long long k){
	long long tm=m;
	long long cnt=0;
	for(long long i=k;i<=n;++i){
		if(tm>=a[k]-a[i]){
			tm-=a[k]-a[i];
			++cnt;
		}
		else{
			break;
		}
	}
	return cnt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;++i){
		cin>>a[i];
		if(i==2){
			at=a[2]-a[1];
		}
		if(i!=1 && a[i]-a[i-1]!=at){
			A=0;
		}
	}
	sort(a+1,a+1+n,cmp);
	if(A){
		cout<<f(1)<<endl;
		return 0;
	}
	for(long long i=1;i<=n;++i){
		ans=max(ans,f(i));
	}
	cout<<ans<<endl;
	return 0;
}*/

//2
#include <iostream>
#include <algorithm>
using namespace std;
const long long N=510000;
long long n,m;
long long a[N];
long long ans;
bool A=1;
long long at;
bool cmp(long long a,long long b){
	return a>b;
}
long long f(long long k){
	long long tm=m;
	long long cnt=0;
	for(long long i=k;i<=n;++i){
		if(tm>=a[k]-a[i]){
			tm-=a[k]-a[i];
			++cnt;
		}
		else{
			break;
		}
	}
	return cnt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;++i){
		cin>>a[i];
		if(i==2){
			at=a[2]-a[1];
		}
		if(i!=1 && a[i]-a[i-1]!=at){
			A=0;
		}
	}
	sort(a+1,a+1+n,cmp);
	if(A){
		cout<<f(1)<<endl;
		return 0;
	}
	for(long long i=1;i<=n;++i){
		ans=max(ans,f(i));
	}
	cout<<ans<<endl;
	return 0;
}
