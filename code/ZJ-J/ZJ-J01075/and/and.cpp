#include<bits/stdc++.h>
using namespace std;
long long a[200005];
set<long long> st;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		long long b;
		cin>>b;
		st.insert(b);
	}
	long long k=1;
	for(auto c:st){
		a[k]=c;
		k++;
	}
	k-=1;
	sort(a+1,a+k+1);
	if(m==1){
		cout<<a[k];
		return 0;
	}
	if(m==2){
		long long d=a[k]&a[k-1];
		cout<<d;
		return 0;
	}
	long long ans=a[k]&a[k-1];
	for(long long i=k-2;i>=k-m+1;i--){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
