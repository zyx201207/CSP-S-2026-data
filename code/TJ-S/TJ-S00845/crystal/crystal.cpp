#include<bits/stdc++.h>
using namespace std;
int n,m;
long long arr[500005];
int ans=0;

//int check(long long x){
//	int cnt=0,mm=m;
//	int l=x-1,r=x+1;
//	long long g=arr[x];
//	while(l>=1 and r<=n and mm>0){
//		if(abs(arr[l]-g)>abs(arr[r]-g)){
//			mm-=abs(arr[r]-g);
//			r++;
//		}else{
//			mm-=abs(arr[l]-g);
//			l--;
//		}
//		cnt++;
//	}
//	return cnt;
//}

int main(){
//	freopen("crystal","r",stdin);
//	freopen("crystal","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
//	long long l=1,r=n;
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
//	sort(arr+1,arr+n+1);
//	while(l<=r){
//		long long mid=(l+r)/2;
//		int ck=check(mid);
//		if(ck>ans){
//			ans=ck;
//			l=mid+1;
//		}else{
//			r=mid-1;
//		}
//	}
//	cout << ans;
	sort(arr+1,arr+n+1);
	arr[0]=1e18;
	for(int i=1;i<=n;i++){
		int cnt=0,mm=m;
		int l=i-1,r=i+1;
		long long g=arr[i];
		while(mm>0){
			if((l<1 and r>n) or ((mm-abs(arr[r]-g))<0 and (mm-abs(arr[l]-g))<0)) break;
			
			if(abs(arr[l]-g)>abs(arr[r]-g) and (mm-abs(arr[r]-g))>=0 and r<=n){
				mm-=abs(arr[r]-g);
				r++;
			}
			else if(abs(arr[l]-g)<=abs(arr[r]-g) and (mm-abs(arr[l]-g))>=0 and l>=1){
				mm-=abs(arr[l]-g);
				l--;
			}
			
			cnt++;
		}	
		ans=max(ans,cnt);
	}
	
	cout << ans;
	
	return 0;
}
