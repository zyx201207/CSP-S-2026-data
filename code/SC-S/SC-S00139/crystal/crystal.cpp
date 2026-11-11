#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	long long n,m,ans=1,z=0;cin>>n>>m;
	vector<long long>A(n),B(n-1);
	for(long long i=0;i<n;i++)cin>>A[i];
	sort(A.begin(),A.end());
	if(m<A[0]){
		cout<<1;
		return 0;
	}
	for(long long i=0;i<n-1;i++){
		B[i]=A[i+1]-A[i];
		if(B[i]!=B[0])z=1;
	}
	int a=0;
	if(z==1){
		while(m>0){
			if(B[a]<B[a+1]){
				m-=(a+1)*(B[a+1]-B[a]);
				B[a]=B[a+1];
				a++,m--,B[a]++;
			}else {
				if((B[a+1]-B[a])*a>m)break;
				else{
					a++;
				}
			}
		}
	}else{
		if(B[0]>1){
			int b=m/B[0];
			for(int i=1;i<=b;i++){
				if(i*B[0]>m){
					cout<<i-1;
					return 0;
				}else if(i*B[0]==m){
					cout<<i;
					return 0;
				}
			}
			if(B[0]*(m-b)>m){
				cout<<b+1;
			}
		}
		else{
			int x=0;
			for(long long i=1;i<=n;i++){
				x=i+x;
				if(x>m){
					cout<<i;
					return 0;
				}else if(x==m){
					cout<<i+1;
					return 0;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		if(B[i]==B[0])ans++;
	}
	cout<<ans+1;
	return 0;
	
}