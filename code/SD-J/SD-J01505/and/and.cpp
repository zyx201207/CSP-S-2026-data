#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long s[200005];
long long ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		long long cnt=2e30-1; 
		for(int i=1;i<=n;i++){
			cnt=cnt&a[i];
		}
		cout<<cnt;
		return 0;
	}
	if(m==1){
		long long cnt;
		for(int i=1;i<=n;i++){
			cnt=max(cnt,a[i]);
		}
		cout<<cnt;
		return 0;
	}
	s[0]=2e30+1;	
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			s[j]=max((s[j-1]&a[i]),s[j]);
		}
    }
	cout<<s[m];
	return 0;
}
