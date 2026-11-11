#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
long long n,mid,p1,p2,ans,k;
long long a[maxn],sum[maxn]={0};char c[maxn];
string s;
struct node{
	int u,v;
}x,y,pub;
void find(long long p,long long q1,long long q2){
	if(q2-q1==1){
		pub.u=q1;pub.v=p-sum[q1-1];
		return;
	}
	long long mid=(q1+q2)/2;
	if(sum[mid-1]>p)find(p,q1,mid);
	else find(p,mid,q2);
}
int main()
{
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];sum[i]=sum[i-1]+a[i];
	}
	mid=sum[n]/2;
	if(sum[n]%2==0){
		p1=mid-1;p2=mid;
	}else{
		p1=mid-1;p2=mid+1;
	}
	while(p1>0&&p2<=sum[n]){
		find(p1,1,n+1);x=pub;find(p2,1,n+1);y=pub;
		if(c[x.u]==c[y.u])k=0;else k=1;
		if(x.v+1==a[y.u]-y.v+1){
			p1-=x.v+1;p2+=x.v+1;ans+=k*(x.v+1);
		}else if(x.v+1<a[y.u]-y.v){
			p1-=x.v+1;p2+=x.v+1;ans+=k*(x.v+1);
		}else{
			p1-=a[y.u]-y.v;p2+=a[y.u]-y.v;ans+=k*(a[y.u]-y.v);
		}
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
