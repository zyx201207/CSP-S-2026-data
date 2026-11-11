#include<bits/stdc++.h>
using namespace std;
long long n,m,s=1,ans,k;
const int N=1e7+5;
int a[N];
bool A=1,B=1;
void s1(){
	s=1;
	while(m>=0){
		m-=s;
		ans++;
		s++;
	}
	cout<<ans;
}
void s2(){
	s=k;
	while(m>=0){
		m-=s;
		ans++;
		s+=k;
	}
	cout<<ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	int t=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			A=0;
		}
		if(i==2) k=a[2]-a[1];
		if(a[i]-a[i-1] != k && i>=2) B=0;
	}
	if(A){
		s1();
		return 0;
	}
	if(B){
		s2();
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		for(int j=i-1;j>=1;j--){
			int x=a[i]-a[j];
			m-=x;
			if(m>=0)	s++;
			else	break;
		}
		ans=max(ans,s);
		s=1;
		m=t;
	}
	cout<<ans;
	return 0;
}