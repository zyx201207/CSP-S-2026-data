//ÄãÏàÐÅÄ§·¨Âð£¿ 



/*#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=-1e10,x;
long long l,r,mid;
bool f;
long long pp(long long k){
	long long all=0,sum=0;
	cout<<k<<endl;
	for(int i=k;i>=1;i--){
		sum++;
		all+=a[k]-a[i];
		if(all>m){
			f=true;
			sum--;
			break;
		}
		cout<<sum<<" "<<all<<endl;
	}
	cout<<sum<<endl<<" "<<endl;
	return sum;
}
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	l=1,r=n;
	while(l<r){
		f=false;
		//cout<<l<<" "<<r<<endl;
		mid=l+(r-l)/2;
		while(a[mid]==a[mid+1]){
			mid++;
		}
		x=pp(mid);
		//cout<<x<<" "<<mid<<endl;
		ans=max(ans,x);
		if(!f){
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	x=pp(l);
	ans=max(ans,x);
	printf("%lld",ans);
	return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005];
long long b[1000005],sum,ans=-1e18,k;
queue<long long> q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	k=1;
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
		q.push(i);
		k++;
		sum+=q.size()*b[i];
		while(sum>m){
			long long y=q.front();
			q.pop();
			k--;
			sum=sum-(a[i]-a[y]);
		}
		ans=max(ans,k);
	}
	printf("%lld",ans);
	return 0;
}
