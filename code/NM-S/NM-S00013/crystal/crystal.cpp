#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005];
long long sum,ans,ans1,com,p,ans2;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch == '-') w=-1;
		ch=getchar();
	}
	while(ch>='0' && ch <='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*w;
}
int check(int x){
	int num=0,l,r;
	l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]>=x){
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	int r1,s;
	long long w=m;
	w-=abs(a[ans]-x),num++;
	r1=ans-1,s=ans+1;
	while(s<=n&& r1>=1 && w>=0 ){
		if(x-a[r1]>a[s]-x){
			if(w>=a[s]-x){
				num++;
			}
			w-=a[s]-x;
			s++;

		}
		else{
			if(w>=x-a[r1]){
				num++;
			}
			w-=(x-a[r1]);
			r1--;
		}
	}
	return num;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		sum+=a[i];
	}
	p=sum/n;
	sort(a+1,a+1+n);
	ans1=check(p);
	ans2=p;
	int l,r;
	l=1,r=p;
	while(l<=r){
		int mid=(l+r)/2;
		int w=check(mid);
		if(w>ans1){
			r=mid-1;
			ans1=w;
		}
		else{
			l=mid+1;
		}
	}
	l=p,r=a[n];
	while(l<=r){
		int mid=(l+r)/2;
		int w=check(mid);
		if(w>ans1){
			l=mid+1;
			ans1=w;
		}
		else{
			r=mid-1;
		}
	}
	cout <<ans1;
	return 0;
}
