#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int b[500005];
bool check(int p){
	int sum=0;
	for(int i=1;i<p;i++){
		sum+=b[i];
	}
	int ans=0;
	for(int i=p;i<=n;i++){
		sum+=b[i];
		sum-=b[i-p];
		if(sum-p*b[i]<=m){
			return 1;
		}
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[n]-a[i];
	}
	int l=1,r=n;
	while(l!=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	cout<<l-1;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
//fc /n crystal.out crystal1.ans 
