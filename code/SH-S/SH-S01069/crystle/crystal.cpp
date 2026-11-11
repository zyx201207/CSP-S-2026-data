#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500008],ans,s[500008],b[500008],cnt,A,B,t,c[500008][2],d[500008],cm;
void solve1(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			cnt=j-i+1;
			if(a[j]*cnt-b[j]+b[i-1]<=m){
				ans=max(ans,cnt);
			}
		}
	}
	cout<<ans<<endl;
}
void solveb(){
	for(int i=1;i<=n;i++){
		t=i+1;
		cnt=i*t/2*s[2];
		if(m<cnt){
			ans=i;
			break;
		}
		 
	}
	cout<<ans<<endl;
}
void solvea(){
	long long o,l;
	ans=0;
	c[1][0]=a[1];
	c[1][1]=1;
	int ct=1;
	for(int i=2;i<=n;i++){
		if(a[i]!=c[ct][0]){
			ct++;
			c[ct][0]=a[i];
		}
		c[ct][1]++;
	} 
	for(int i=1;i<=ct;i++){
		b[i]=b[i-1]+c[i][0]*c[i][1];
	}
	for(int i=1;i<=ct;i++){
		for(int j=i+1;j<=ct;j++){
			cnt=0;
			for(int k=i;k<=j;k++){
				cnt+=c[k][1];
			}
			if(c[j][0]*cnt-b[j]+b[i-1]<=m){
//				cm=m;
//				l=c[j][0]*cnt-b[j]+b[i-1];
//				cm-=l;
//				o=c[j][0]-c[i-1][0];
//				if(o!=0)cnt+=cm/o;
				if(ans<=cnt)ans=cnt;
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		A=max(A,a[i]);
	}
	sort(a+1,a+n+1);
	B=1;
	for(int i=2;i<=n;i++){
		s[i]=a[i]-a[i-1];
		if(s[i]!=s[2]){
			B=0;
		}
	}
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	if(n<=5000){
		solve1();
		return 0;
	}
	if(B==1){
		solveb();
		return 0;
	} 
	if(A<=100){
		solvea();
		return 0;
	}
	
	return 0;
}
