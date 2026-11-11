#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N];
long long suf[N];
map<int,long long> flag; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	int flag1=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=2&&a[i]!=a[i-1]){
			flag1=1;
		}
	}
	if(flag1==0){
		cout<<n;
		return 0;
	}
	double _x=0;
	for(int i=1;i<=n;i++){
		_x+=a[i];
	}
	_x/=(n*1.0);
	for(int i=1;i<=n;i++){
		if(a[i]>=_x+m||a[i]<=_x-m){
			flag[i]=a[i];
			a[i]=0;
		}
	}
	_x=0;
	for(int i=1;i<=n;i++){
		_x+=a[i];
		if(flag.count(i)){
			a[i]=1e13;
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
	}
	_x/=(n*1.0);
	long long t=1e12;
	int real_i;
	for(int i=1;i<=n;i++){
		if(flag.count(i)){
			a[i]=flag[i];
		}
		if(abs(a[i]-_x)<=t){
			t=abs(a[i]-_x);
			real_i=a[i];
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]<real_i){
			suf[i]=abs(a[i]-real_i);
		}
		else{
			suf[i]=(a[i]-real_i)*(i-1);
		}
	}
	sort(suf+1,suf+n+1);
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(m<=0){
			break;
		}
		else{
			m-=suf[i];
			if(m>=0){
				ans++; 
			}
		}
	}
	cout<<ans;
	return 0;
}