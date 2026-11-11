#include<bits/stdc++.h>
using namespace std;

long long two(long long a){
	long long s=0,l=1;
	while(a>0){
		s+=a%2*l;
		a/=2;
		l*=10;
	}
	return s;
}

long long yu(long long a,long long b){
	long long s=0,l=1,r=10,w=1;
	while (a>0 and b>0){
		if((a%r-a%l)/l==1 and (b%r-b%l)/l==1)s+=1*w;
		w*=2;
		a/=10;
		b/=10;
	}
	return s;
}







int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	long long n,m;
	scanf("%lld%lld",&n,&m);
	vector<long long>a(n,0);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a.begin(),a.end());
	for(int i=0;i<m-1;i++){
		a[i+1]=yu(two(a[n-i-1]),two(a[n-i-2]));
		if(i==m-2){
			cout<<a[i+1];
		}
		
	}
	return 0;
}
