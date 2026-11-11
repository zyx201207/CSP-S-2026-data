#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
long long a[maxn];
int f;
long long sum;
int cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long l=a[1],r=a[n],mid=0;
	while(l<r){
		sum=0;
		cnt=0;
		mid=(l+r)/2;
		for(int i=1;i<=n;i++){
			cnt++;
			sum=sum+abs(a[i]-mid);
			if(sum<=m){
				f=max(f,cnt);
			}
		}
		if(sum<=m){
			l=mid+1;
			f=max(f,cnt);
		}
		else{
			r=mid-1;
		}
	}
	cout<<f;
	return 0;
}