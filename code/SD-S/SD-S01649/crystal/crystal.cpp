#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],d;
bool z=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	sort(a,a+n);
	for(int i=1;i<n;i++){
		if(a[i]==a[i-1]){
			d++;
		}
	}
	if(d==n-1){
		cout<<n;
		return 0;
	}
	long long s=0;
	for(int i=1;i<n;i++){
		long long p=i,ans=1,m1=m;
		while(p>0){
			m1-=a[i]-a[--p];
			if(m1>=0){
				ans++;
			}
			
		}
		s=max(s,ans);
	}
	cout<<s;
	return 0;
} 
