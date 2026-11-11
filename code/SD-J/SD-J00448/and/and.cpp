#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long sd[100009],sc[100009],sa[100009];
	long long ans;
long long erjinzhi(long long a){
	memset(sd,0,sizeof(sd));
	long long i=1;
	while(a>0){
		sd[i]=a%2;
		a=a/2;
	}
	reverse(sd+1,sd+1+i);
	return i;
}
long long jinzhi(long long a){
	memset(sc,0,sizeof(sc));
	long long i=1;
	while(a>0){
		sc[i]=a%2;
		a=a/2;
	}
	reverse(sc+1,sc+1+i);
	return i;
}
void xx(long long a){
	for(int i=1;i<=a;i++){
		sa[i]=sd[i] and sc[i];
	}
}
long long zhuan(long long a){
	long long ans=0;
	for(int i=a;i>=1;i--){
		ans+=sa[i]*pow(2,i-1);
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long a[n+2];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	reverse(a+1,a+1+n);
	long long t=jinzhi(a[1]);
	for(int i=2;i<=m;i++){
		long long tu=max(erjinzhi(a[i]),t);
		xx(tu);
		long long yu=zhuan(tu);
		t=jinzhi(yu);
		ans=max(ans,t);
	}
	cout<<ans;
	return 0;
}
