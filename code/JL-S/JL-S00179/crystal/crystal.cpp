#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long mn=1000;
	long long sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		//cerr<<a[i]<<' ';
	}
	//cerr<<endl;
	//cerr<<sum<<endl;
	sum=sum/n;
	//cerr<<sum<<endl;
	long long pos;
	for(long long i=1;i<=n;i++){
		if(a[i]==sum){
			pos=i;
			break;
		}
		if(a[i]>sum){
			if(a[i]-sum<=mn) {
				pos=i;
				mn=a[i]-sum;
			}
		}
		if(a[i]<sum){
			if(sum-a[i]<=mn) {
				pos=i;
				mn=sum-a[i];
			}
		}
	}
	long long pj=a[pos];
	//cerr<<pos<<endl<<pj<<endl;
	long long x=0,y=0;
	for(long long i=1;i<pos;i++){
		x=x+(pj-a[i]);
	}
	for(long long i=pos+1;i<=n;i++){
		y=y+(a[i]-pj);
	}
	long long cnt=1;
	//cerr<<x<<' '<<y<<endl;
	if(x>y){
		for(long long i=pos+1;i<=n;i++){
			if(m<a[i]-pj) break;
			cnt++;
			m=m-(a[i]-pj);
		}
		for(long long i=pos-1;i>=1;i--){
			if(m<pj-a[i]) break;
			cnt++;
			m=m-(pj-a[i]);
		}
		
	}
	else if(x<y){
		for(long long i=pos-1;i>=1;i--){
			if(m<pj-a[i]) break;
			cnt++;
			m=m-(pj-a[i]);
		}
		for(long long i=pos+1;i<=n;i++){
			if(m<a[i]-pj) break;
			cnt++;
			m=m-(a[i]-pj);
		}
		
	}
	cout<<cnt<<endl;
	return 0;
}
