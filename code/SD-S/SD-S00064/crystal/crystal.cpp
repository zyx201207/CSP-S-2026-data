//#include<bits/stdc++.h>
//using namespace std;
//long long a[500005];
//long long ocnt,id;
//int maxx;
//int main(){
////	freopen("crystal.in","r",stdin);
////	freopen("crystal.out","w",stdout);
//	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//	int n;
//	long long m;
//	cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//	}
//	sort(a+1,a+n+1);
//	long long p1=a[1];
//	long long p2=a[n];
//	for(int i=p1;i<=p2;i++){
//		int sum=0,cnt=0;
//		for(int j=1;j<=n;j++){
//			if(a[j]>i){
//				break;
//			}
//			sum+=i-a[j];
//			cnt++;
//			if(sum>m){
//				cnt--;
//				break;
//			}
//		}
//		maxx=max(maxx,cnt);
//	}
//	cout<<maxx;
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int maxx,cnt;
long long sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	sort(a+1,a+n+1);
	int c=a[2]-a[1];
	bool flag=0;
	a[0]=a[1]-c;
	for(int i=1;i<=n;i++){
		if(a[i]-a[i-1]!=c){
			flag=1;
			continue;
		}
	}
	if(flag==0){
		for(int i=n;i>=1;i--){
			sum+=a[n]-a[i];
			cnt++;
			if(sum>m){
				cnt--;
				break;
			}
		}
		cout<<cnt;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cnt=0,sum=0;
		for(int j=1;j<=i;j++){
			sum+=(a[i]-a[j]);
			cnt++;
			if(sum>m){
				cnt--;
				break;
			}
		}
		maxx=max(maxx,cnt);
	}
	cout<<maxx;
	return 0;
}

