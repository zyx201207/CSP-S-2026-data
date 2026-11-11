#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
unsigned long long a[N];
unsigned long long l,r;
long long b[N];
char c[N];
bool tp;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%lld",&b[i]);
		cin>>c[i];
		a[i]=a[i-1]+b[i];
	}
	unsigned long long mid=0,at;
	char ct;
	long long bt;
	bool flag=true;
	if(a[n]%2==0) {
		for(int i=1; i<=n; i++) {
			if(mid!=0) {
				unsigned long long t=a[i];
				a[i]=at;
				at=t;
				char t2=c[i];
				c[i]=ct;
				ct=t;
				long long t3=b[i];
				b[i]=bt;
				bt=t;
			}
			if(a[i-1]<a[n]/2&&a[i]>=a[n]/2&&flag) {
				mid=i;
				flag=false;
				if(a[i]==a[n]/2) break;
				at=a[i+1];
				ct=c[i+1];
				bt=b[i+1];
				a[i+1]=a[i];
				b[i+1]=a[i+1]-a[n]/2;
				c[i+1]=c[i];
				a[i]=a[n]/2;
				b[i]=a[i]-a[i-1];	
				n+=1;
				i+=1;
			}
		}
		l=a[mid],r=a[mid]+1;
	}else{
		tp=true;
		for(int i=1; i<=n; i++) {
			if(mid!=0) {
				unsigned long long t=a[i];
				a[i]=at;
				at=t;
				char t2=c[i];
				c[i]=ct;
				ct=t;
				long long t3=b[i];
				b[i]=bt;
				bt=t;
			}
			if(a[i-1]<=a[n]/2&&a[i]>a[n]/2&&flag) {
				mid=i;
				flag=false;
				if(a[i-1]==a[n]/2){
					b[i]-=1;
					mid=i-1;
					break;
				}
				at=a[i+1];
				ct=c[i+1];
				bt=b[i+1];
				a[i+1]=a[i];
				b[i+1]=a[i+1]-a[n]/2-1;
				c[i+1]=c[i];
				a[i]=a[n]/2;
				b[i]=a[i]-a[i-1];	
				n+=1;
				i+=1;
			}
		}
		l=a[mid],r=a[mid]+2;
	}
	
	int now_l=mid,now_r=mid+1;
	unsigned long long sum=0;
	int have=0;
	while(now_l!=0){
		have=0;
		while(have!=b[now_l]){
			have+=a[now_r]-r+1;
			r=a[now_r]+1;
			if(have>b[now_l]){
				r-=have-b[now_l];
				have=b[now_l];
				if(c[now_r]==c[now_l]) {
					if(tp&&now_r==mid+1) sum-=1;
					sum+=r-a[now_r-1]-1;
				}
			}else {
				if(c[now_r]==c[now_l]) {
					if(tp&&now_r==mid+1) sum-=1;
					sum+=r-a[now_r-1]-1;
				}
				now_r+=1;
			}
		}
		now_l-=1;
	}
	unsigned long long ans=a[n]/2-sum;
	cout<<ans;
	return 0;
}
/*
7
1 a 1 s 1 b 3 t 1 x 1 y 1 z
*/