#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int ans=0,n,m;
int a[N];
int check(int x){
	int sum=9,cnt=0;
	int i=1;
	while(x!=0){
		sum=sum*10+x%2;
		x/=2;
		i++;
	}
	for(int j=1;j<i;j++){
		cnt=cnt*10+sum%10;
		sum/=10;
	}
	return cnt;
}
int f(int x,int y){
	int cnt=0;
	while(x!=0&&y!=0){
		cnt=cnt*10+(x%10)&(y%10);
		x/=10,y/=10;
	}
	return cnt;
}
int g(int x){
	int ans=0,i=0;
	while(x!=0,i++){
		if(x%10==1){
			int cnt=1;
			for(int j=1;j<=i;j++){
				cnt*=2;
			}
			ans+=cnt;
		}
	}
	return ans;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxn=INT_MIN;
	for(int i=1;i<=n;i++){
		int x=a[i];
		for(int j=i+1;j<=m;j++){
			x=g(f(x,a[j]));
		}
		maxn=max(maxn,x);
	}
	cout<<maxn;
	return 0; 
}

