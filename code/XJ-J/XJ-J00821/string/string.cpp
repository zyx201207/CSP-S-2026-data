//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//using namespace std;
//int main(){
////	freopen("string.in","r",stdin);
////	freopen("string.out","w",stdout);
//	long long ans=0;
//	int n;
//	cin>>n;
//	int a[200005];
//	char c[200005];
//	for(int i=0;i<n;i++){
//		cin>>a[i];
//		cin>>c[i];
//	}
//	char c1[100005];
//	char c2[100005];
//	int a1[100005];
//	int a2[100005];
//	for(int i=0;i<n/2;i++){
//		c1[i]=c[i];
//		a1[i]=a[i];
//	}
//	for(int j=n-i-1;j>=n/2+1;j--){
//		c2[i]=c[i];
//		a2[i]=a[i];
//	}
//	int x,y;
//	x=0;
//	y=n-1;
//	for(int i=0;i<n/2;i++){
//		if (c1[x]!=c2[y]){
//			if (a1[x]<a2[y]){
//				ans+=a1[x];
//				x++;
//				a2[y]-=a1[x-1];
//			}
//		}else{
//			
//		}
//	}
//	cout<<ans;
//	return 0;
//}
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long ans=0;
	int n;
	cin>>n;
	int a[200005];
	char c[200005];
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	for(int i=0;i<n/2;i++){
		if (c[i]!=c[n-i-1]){
			if (a[i]<=a[n-i-1]){
				ans+=a[n-i-1];
			}else{
				ans+=a[i];
			}
		}
	}
	cout<<ans;
	return 0;
}