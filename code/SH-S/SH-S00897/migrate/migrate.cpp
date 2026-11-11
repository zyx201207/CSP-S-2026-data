#include<bits/stdc++.h>
using namespace std;
const int SIZE=2e6+9;
void read(long long &x){
	x^=x;
	int f=1;
	char a=getchar();
	while(!('0'<=a&&a<='9')){
		if(a=='-')f=-1;
		a=getchar();
	}
	while('0'<=a&&a<='9'){
		x=x*10+a-'0';
		a=getchar();
	}
	x*=f;
	return ;
}

long long c,t,n,d,cnt,ans;
long long D[SIZE];



int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(c);
	read(t);
	int i;
	while(t--){
		ans^=ans;
		read(n);
		read(d);
		for(i=1;i<=n;i++)read(D[i]);
		int l,r,mid,lmax,rmax,lmaxr,rmaxl;
		int maxLr,maxRl;
		l=2,r=n;
		while(l<r){
			mid=(l+r+1)>>1;
			if(D[mid]-D[1]<=d)l=mid;
			else r=mid-1;
		}
		maxLr=l;
		l=1,r=n-1;
		while(l<r){
			mid=(l+r)>>1;
			if(D[n]-D[mid]<=d)r=mid;
			else l=mid+1;
		}
		maxRl=r;
		for(i=2;i<n;i++){
			l=1,r=i-1;
			while(l<r){
				mid=(l+r)>>1;
				if(D[i]-D[mid]<=d)r=mid;
				else l=mid+1;
			}
			lmax=r;
			l=lmax+1,r=n;
			while(l<r){
				mid=(l+r+1)>>1;
				if(D[mid]-D[lmax]<=d)l=mid;
				else r=mid-1;
			}
			lmaxr=l;
			l=i+1,r=n;
			while(l<r){
				mid=(l+r+1)>>1;
				if(D[mid]-D[i]<=d)l=mid;
				else r=mid-1;
			}
			rmax=l;
			l=1,r=rmax-1;
			while(l<r){
				mid=(l+r)>>1;
				if(D[rmax]-D[mid]<=d)r=mid;
				else l=mid+1;
			}
			rmaxl=r;
			int now,prenow;//cout<<rmaxl<<" "<<lmaxr<<endl;
			if(lmaxr-rmaxl==1){
				ans++;
				now=lmax;
				while(now!=1){
					l=1,r=now-1;
					while(l<r){
						mid=(l+r)>>1;
						if(D[now]-D[mid]<=d)r=mid;
						else l=mid+1;
					}
					ans++;
					prenow=now;
					now=r;
				}
				if(prenow!=maxLr)ans--;
				now=rmax;
				while(now!=n){
					l=now+1,r=n;
					while(l<r){
						mid=(l+r+1)>>1;
						if(D[mid]-D[now]<=d)l=mid;
						else r=mid-1;
					}
					ans++;
					prenow=now;
					now=l;
				}
				if(prenow!=maxRl)ans--;
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
