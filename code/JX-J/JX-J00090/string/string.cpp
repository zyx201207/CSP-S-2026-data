#include<bits/stdc++.h>
using namespace std;
bool f;
int n;
long long mid,ans,ma;
int a[200005];
long long sum[200005];
char c[200005];
long long m;
char lx,rx;
int lnum,rnum;
void work(){
	if(lnum<=0||rnum<=0) return;
	bool ff=(lx==rx);
	if(lnum<rnum){
		if(ff==0) ans+=lnum;
		lnum=0;
		lx=' ';
		rnum-=lnum;
	}
	else if(lnum>rnum){
		if(ff==0) ans+=rnum;;
		rnum=0;
		rx=' ';
		lnum-=rnum;
	}
	else if(lnum==rnum){
		if(ff==0) ans+=lnum;
		rnum=lnum=0;
		rx=' ';
		lx=' ';
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	c[0]='.';
	c[n+1]='.';
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum[i]=sum[i-1]+a[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	m=sum[n];
	if(m%2==0) f=1;
	if(f) ma=m/2;
	else ma=m/2+1;
	for(int i=1;i<=n;i++){
		if(sum[i-1]<ma&&sum[i]>=ma){
			mid=i;
			break;
		}
	}
	if(f){
		lnum=ma-sum[mid-1];
		lx=c[mid];
		rnum=sum[mid]-ma;
		rx=c[mid];
		work();
	}
	else{
		lnum=ma-sum[mid-1]-1;
		lx=c[mid];
		rnum=sum[mid]-ma;
		rx=c[mid];
		work();
	}
	int l=mid,r=mid;
	while(l>=1&&r<=n){
		if(lnum<=0&&rnum<=0){
			l--;
			r++;
			lx=c[l];
			lnum=a[l];
			rx=c[r];
			rnum=a[r];
		}
		else if(lnum<=0){
			l--;
			lx=c[l];
			lnum=a[l];
		}
		else if(rnum<=0){
			r++;
			rx=c[r];
			rnum=a[r];
		}
		work();
	}
	if(l==0&&r==n+1){
		cout<<ans;
		return 0;
	}
	if(l==0){
		cout<<1<<" ";
		ans+=lnum;
		for(int i=r;i<=n;i++){
			ans+=a[i];
		}
	}
	else{
		ans+=rnum;
		for(int i=l;i>=n;i--){
			ans+=a[i];
		}
	}
	cout<<ans;
	return 0;
}
