#include<bits/stdc++.h>
using namespace std;
const int N=5*10e5+10;
long long n,m,ans,sum;
long long a[N];
bool f=1;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>a[1]>>a[2];
	int c=a[2]-a[1];
	for(int i=3;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]!=c) f=0;
	}
	if(f){
		for(int i=1;i<=n;i++){
			if(m<c*i*(i-1)/2) break;
			ans=i;
		}
		cout<<ans;
	}
	else{
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			sum=0;
			int b=m;
			for(int j=i;j<=n;j++){
				b=b-a[i]+a[j];
				if(b<0) break;
				sum++;
			}
			ans=max(ans,sum);
		}  
		cout<<ans;
	}
	return 0;
} 