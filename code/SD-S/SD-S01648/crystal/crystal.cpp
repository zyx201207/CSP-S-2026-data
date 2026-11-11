#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int qq=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ppp=(a[2]-a[1]),pp=1;
	for(int i=1;i<=n-1;i++){
		if(a[i+1]!=a[i]){
			qq=0;
		}
		if(a[i+1]-a[i]!=ppp){
			pp=0;
		}
	}
	if(qq==1){
		cout<<n;
		return 0;
	}
	if(pp==1){
		long long pppp=ppp;
		int zmjjkk=0;
		while(m-pppp>=0){
			m=m-pppp;
			ppp+=pppp;
			zmjjkk++;
			if(zmjjkk==n){
				cout<<n;
				return 0;
			}
		}
		cout<<zmjjkk;
		return 0;
	}
	sort(a+1,a+n+1);
	long long l=a[1],r=a[n],sum=0,cnt1=1;
	long long mid=(l+r)/2;
	long long u=0,ua=0,un=0;
	for(int i=1;i<=n;i++){
	   	b[i]=mid-a[i];
	}
	sort(b+1,b+n+1);
	while(sum+b[cnt1]<=m&&cnt1<=n){
		if(b[cnt1]>=0){
			sum=sum+b[cnt1];
			u++;
		}
		cnt1++;
	}
	long long o=m-sum;
	sum=0;
	cnt1=1;
	for(int i=1;i<=n;i++){
	   	b[i]=a[1]-a[i];
	}
	sort(b+1,b+n+1);
	while(sum+b[cnt1]<=m&&cnt1<=n){
		if(b[cnt1]>=0){
			sum=sum+b[cnt1];
			ua++;
		}
		cnt1++;
	}
	long long p=m-sum;
	sum=0;
	cnt1=1;
	for(int i=1;i<=n;i++){
	   	b[i]=r-a[i];
	}
	sort(b+1,b+n+1);
	while(sum+b[cnt1]<=m&&cnt1<=n){
	   	if(b[cnt1]>=0){
			sum=sum+b[cnt1];
			un++;
		}
		cnt1++;
	}
	long long k=m-sum;
	sum=0;
	cnt1=1;
	if(ua>u){
		r=mid;
		k=o;
		un=u;
	}
	if(un>u){
		l=mid;
		ua=u;
		p=o;
	}
	if(ua==un){
		if(p>k){
			r=mid;
			un=u;
			k=o;
		}
		else{
			l=mid;
			ua=u;
			p=o;
		}
	}
	if(u==n||un==n||ua==n){
		cout<<n;
		return 0;
	}
	while(r-l>1){
		int zzdmid=(r+l)/2;
		long long ux=0;
		for(int i=1;i<=n;i++){
		   	b[i]=zzdmid-a[i];
		}
		sort(b+1,b+n+1);
		while(sum+b[cnt1]<=m&&cnt1<=n){
			if(b[cnt1]>=0){
				sum=sum+b[cnt1];
				ux++;
			}
			cnt1++;
		}
		cnt1=1;
		o=m-sum;
		sum=0;
		if(un>ua){
			ua=ux;
			p=o;
			l=zzdmid;
		}
		if(ua>un){
			r=zzdmid;
			un=ux;
			k=o;
		}
		if(un==ua){
		    if(p>=k){
				r=zzdmid;
				un=ux;
				k=o;
			}
			else{
				ua=ux;
			    p=o;
			    l=zzdmid;
			}
		}
	}
	cout<<max(ua,un);
} 
