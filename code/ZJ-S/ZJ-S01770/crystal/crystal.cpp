#include<bits/stdc++.h>
using namespace std;
long long a[500050];
long long pre[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	int cnt=1;
	int r=1;
	for(int l=1;l<=n;l++){
		if(r>n){
			break;
		}
		while(a[r]*(r-l+1)-(pre[r]-pre[l-1])<=m){
			
			cnt=max(cnt,r-l+1); 
			r++;
			if(r>n){
				break;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}
