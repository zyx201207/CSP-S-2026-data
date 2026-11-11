#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
bool flaga=true,flagb=true;
vector<long long> a(500010);
void slove1(){
	int ans=1;
	sort(a.begin()+1,a.begin()+n+1);
	for(int i=1;i<=n;i++){
		int cnt=1;
		long long k=m;
		for(int j=i-1;j>=1;j--)
			if((a[i]-a[j])<=k) k-=(a[i]-a[j]),cnt++;
			else break;
		ans=max(ans,cnt);
	}
	cout<<ans;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cin>>a[1]>>a[2];
	if(a[1]!=1 || a[2]!=2) flaga=false; 
	long long gc=a[2]-a[1];
	for(int i=3;i<=n;i++){
		cin>>a[i];
		if((a[i]-a[i-1])!=gc) flagb=false;
		if(a[i]!=i) flaga=false; 
	}
	if(n<=5000){
		slove1(); 
	} else if (flaga){
		int ans=0;
		long long add=0;
		for(int i=1;i<n;i++){
			add+=i;
			if(m>=add) ans=i+1;	
			else break;
		}
		cout<<ans;
	} else if(flagb){
		int ans=0;
		long long add=0;
		for(int i=1;i<n;i++){
			add+=i*gc;
			if(m>=add) ans=i+1;	
			else break;
		}
		cout<<ans;
	} else {
		
	}
	return 0;
}
