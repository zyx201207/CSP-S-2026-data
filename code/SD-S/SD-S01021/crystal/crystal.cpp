#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long sum[500010];
long long n,m;
bool check(int number){ //以地几个数字为基准 
	int ans=0;
	for(int i=1;i<=n;i++){ //以地几个数为基准 
//		cout<<"以地"<<i<<"个为基准\n";
		int l=0,r=i-1,mid;//能拉几个上来 ,从后往前 
		
			while(l<=r){
				mid=(l+r)/2;
//				cout<<mid<<"\n";
//				cout<<(mid*a[i] - (sum[i-1]-sum[i-1-mid]))<<"\n\n";
				if((mid*a[i] - (sum[i-1]-sum[i-1-mid])) <= m){ //5
					ans=mid+1;
					if(ans>=number) return 1;
					l=mid+1;
				}else{
					r=mid-1;
				}
//				cout<<"答案:"<<ans<<"\n"; 
			}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	long long l=1,r=n,mid,ans;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
}
/*
10 5
3 6 8 9 11 14 15 16 1 4



*/
