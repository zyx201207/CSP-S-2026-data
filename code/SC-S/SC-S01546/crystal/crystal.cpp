#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,Max=1;
long long a[500005],b[500005],c[500005];
long long q[45];
bool flag1=1,flag2=1;
void f(int now,int le,int ri){
	long long w;
	if(n==1){
		for(w=1;w<=n&&m-b[w]>=0;w++);
		Max=max(Max,w);
	}
	else if(now==n){
		w=1;
		for(int i=n-1;i>=1;i--){
			if(m-(a[i+1]-a[i])>=0){
				m-=a[i+1]-a[i];
				w++;
			}
		}
		Max=max(Max,w);
	}
/*	else{
		while(m>=0&&le>=1&&ri<=n){
			if(a[now]-a[le]<a[ri]-a[now]){
				m-=a[now]-a[le];
				le--;
			}
			else if(a[now]-a[le]<a[ri]-a[now]){
				m-=a[ri]-a[now];
				ri--;
			}
			else{
				for(int i=1;)
			}
		} 
	}*/
}
void f2(int t){
	if(t>m){
		for(int i=1;i<=44;i++)q[i]=0;
		for(int i=1;i<=n;i++){
			if(c[i]<0){
				q[abs(c[i])]++;
			}
			q[20+1+c[i]]++;
		}
		for(int i=1;i<=41;i++){
			Max=max(Max,q[i]);
		}
		return;
	}
	for(int i=1;i<=n;i++){
		c[i]++;
		f2(t+1);
		c[i]--;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=a[i];
		if(a[i]!=i){
			flag1=0;
		}
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]&&i>2){
			flag2=0;
		}
	}
	sort(a+1,a+1+n);
	if(flag1){
		ans=1;
		for(int i=1;i<=n-1;i++){
			if(m-i>=0){
				m-=i;
				ans++;
			}
			else break;
		}
		cout<<ans;
	}
	else if(flag2){
		long long x=a[2]-a[1];
		ans=1;
		for(int i=1;i<=n-1;i++){
			if(m-i*x>=0){
				m-=i*x;
				ans++;
			}
		}
		cout<<ans;
	}
	else if(n<=16){
		f2(1);
		cout<<Max;
	}
	else{
		b[1]=0;
		for(int i=2;i<=n;i++){
			b[i]=b[i-1]+a[i]-a[i-1];
		}
		for(int i=1;i<=n;i++){
			f(i,i-1,i+1);
		}
		cout<<Max;
	}
	return 0;
}