#include<bits/stdc++.h>
using namespace std;
long long summ,minn=1e17,cnt,n,sum[210000],ans;
struct node {
	long long sum;
	string s;
} a[210000],b[210000];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i].sum>>a[i].s;
		summ+=a[i].sum;
	}

	for(int i=1; i<=n; i++) {
		if(a[i].s==a[i+1].s) {	
		long long num=0;
		string p=a[i].s;
			while(i<=n&&p==a[i].s) {
				num+=a[i].sum;
				i++;
			//	cout<<i<<" ";
			}
		//	cout<<"\n";
			b[++cnt].sum=num;
			b[cnt].s=a[i-1].s;
			i--;
		} else {
			b[++cnt].sum=a[i].sum;
			b[cnt].s=a[i].s;
		}
	}
	if(cnt==1) {
		cout<<"0";
		return 0;
	}
	//cout<<cnt<<"\n";
	for(int i=1; i<=cnt; i++) {
		sum[i]=sum[i-1]+b[i].sum;
	//	cout<<b[i].s<<" "<<b[i].sum<<"\n";
	}
	//cout<<"\n";
	long long l=1,r=cnt;
	if(cnt%2!=0) {
		while(l<r) {
			long long mid=(l+r)/2;
			if(sum[mid]<summ/2+1) {
				l=mid+1;
			} else {
				r=mid;
			}
		}
        ans+=abs(summ/2-sum[l-1]-(sum[l]-summ/2-1));
	//	cout<<summ/2+1<<" "<<sum[l-1]<<" "<<sum[l]<<"\n";
		long long i=l-1,j=l+1,k1=0,k2=0;
		while(i>=1&&j<=cnt) {
			long long minx=min(b[i].sum-k1,b[j].sum-k2);
			if(b[i].s!=b[j].s){
				ans+=minx;
			}
			k1+=minx;
			k2+=minx;
		//	cout<<i<<" "<<j<<":"<<ans<<" "<<minx<<"\n";
			if(k1==b[i].sum) {
				k1=0;
				i--;
			}
			if(k2==b[j].sum) {
				k2=0;
				j++;
			}
		}
		if(i>=1&&(summ/2-sum[l-1])>(sum[l]-summ/2-1)){
			ans+=k1;
		}
		if(j<=cnt&&(summ/2-sum[l-1])<(sum[l]-summ/2-1)){
			ans+=k2;
		}
	} else {
		while(l<r) {
			long long mid=(l+r)/2;
			if(sum[mid]<summ/2+1) {
				l=mid+1;
			} else {
				r=mid;
			}
		}
		long long i=l-1,j=l,k1=0,k2=0;
	//	cout<<i<<" "<<j<<"\n";
		while(i>=1&&j<=cnt) {
			long long minx=min(b[i].sum-k1,b[j].sum-k2);
		//	cout<<i<<" "<<j<<":"<<minx<<"\n";
			if(b[i].s!=b[j].s){
				ans+=minx;
			}
			k1+=minx;
			k2+=minx;
			if(k1==b[i].sum) {
				k1=0;
				i--;
			}
			if(k2==b[j].sum) {
				k2=0;
				j++;
			}
		}
		if(i>=1&&(summ/2-sum[l-1])>(sum[l]-summ/2-1)){
			ans+=k1;
		}
		if(j<=cnt&&(summ/2-sum[l-1])<(sum[l]-summ/2-1)){
			ans+=k2;
		}
	}
	cout<<ans;
	return 0;
}
