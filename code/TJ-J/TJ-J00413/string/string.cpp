#include<bits/stdc++.h>
using namespace std;
struct node{
	long long len;
	string s;
}a[300000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;
	cin >> n;
	for(int i=1;i<=n;i++)cin >> a[i].len >> a[i].s;
	long long l=1,r=n;
	while(l<=r){
		if(a[l].s!=a[r].s)ans+=min(a[l].len,a[r].len);
		if(a[l].len>a[r].len){
			a[l].len-=a[r].len;
			r--;
		}
		else if(a[l].len<a[r].len){
			a[r].len-=a[l].len; 
			l++;
		}
		else{
			l++;
			r--;
		}
	}
	cout << ans;
	return 0;
}
