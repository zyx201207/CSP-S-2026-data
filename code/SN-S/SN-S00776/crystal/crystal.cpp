#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5;
long long cnt1;
long long n,m,a[maxn],k[maxn],sum=0,dt[maxn]; // n m a k
bool flag=1,flag2=1;
int main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		if(a[i]<0) flag2=0;
		if(i!=1){
			k[i]=a[i]-a[i-1];
		}
	}
	for(int i=2;i<=n-1;i++){
		if(k[i]!=k[i+1]) flag=0;
	}
	if(flag2&&flag){ // A&B
		int g=n-1;
		int d=(1+g)*g/2;
		cout<<d*k[2];
		return 0;
	} 
	// others
	double avrd=sum/n;
	int avr=INT_MAX;
	int mn=INT_MAX;
	for(int i=1;i<=n;i++){
		if(abs(avrd-a[i])<mn){
			mn=avrd-a[i];
			avr=a[i];
		}
	}
	int cnt2=1,ANS;
	sort(a+1,a+n);
	for(int i=1;i<=n;i++){
		dt[i]=abs(avr-a[i]);
	}	
	while(1){
		sort(dt+1,dt+n);		
		if(dt[cnt2]>0){
			dt[cnt2]--;
			m--;
		}
		else if(cnt2>n){
			cout<<n;
			return 0;
		}
		else{
			cnt2++;
		}
		if(m==0) break;
	}
	for(int i=1;i<=n;i++){
		if(dt[i]==0) ANS++;
	}
	cout<<ANS;
	return 0;
} 

