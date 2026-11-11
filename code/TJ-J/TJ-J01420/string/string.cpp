//#include<bits/stdc++.h>
//using namespace std;
//int n;
//int k = 0;
//int ans = 0;
//string s;
//int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
//	cin >> n;
//	for(int i = 1;i<=n;i++){
//		int x;
//		cin >> x;
//		char c;
//		cin >> c;
//		k+=x;
//		for(int j = 1;j<=x;j++){
//			s+=c;
//		}
//	}
//	cout << k;
//	for(int i = 0;i<k;i++){
//		if(s[i]!=s[k-i-1]){
//			ans++;
//			s[i] = s[k-i-1];
//		}
//	}
//	cout << ans;
////	freopen("string.in","r",stdin);
////	freopen("string.out","w",stdout);
//	
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll ans = 0LL;
string s;
struct node{
	ll x;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(ll i = 1;i<=n;i++){
		cin >> a[i].x >> a[i].c;
	}
	ll l = 1,r = n;
	ll ans = 0;
	while(l<r){
		if(a[l].c!=a[r].c){
			if(a[l].x<a[r].x){
				ans+=a[l].x;
				a[r].x-=a[l].x;
				a[l].x = 0LL;
				l++;
			}
			else if(a[l].x>a[r].x){
				ans+=a[r].x;
				a[l].x-=a[r].x;
				a[r].x = 0LL;
				r--;
			}
			else{
				ans+=a[l].x;
				a[l].x = 0LL;
				a[r].x = 0LL;
				l++;
				r--;
			}
		}
		else{
			if(a[l].x<a[r].x){
				a[r].x-=a[l].x;
				a[l].x = 0LL;
				l++;
			}
			else if(a[l].x>a[r].x){
				a[l].x-=a[r].x;
				a[r].x = 0LL;
				r--;
			}
			else{
				a[l].x = 0LL;
				a[r].x = 0LL;
				l++;
				r--;
			}
		}
	} 
	cout << ans;
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	
	return 0;
}

