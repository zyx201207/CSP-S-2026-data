#include<bits/stdc++.h>
using namespace std;
const int N = 500005;
int n;
long long m,a[N];
int check(int x){
	int cnt = 0,l = 1;
	long long w = m;
	for(l;l<=n;l++){
		if(a[l]>x){
			l--;
			break;
		}
	}
	for(int i = l;i >= 1;i--){
		if(x<a[i])break;
		w -= (x-a[i]);
		if(w>=0)cnt++;
		else break;
	} 
	return cnt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)cin>>a[i];
	
	if(n>5000){
		int flag = 1;
		long long k = a[2]-a[1];
		for(int i = 2;i<=n;i++){
			if(a[i]-a[i-1] != k)flag = 0;
		}
		if(flag==0){
			sort(a+1,a+n+1);
			int cnt = 0;
			for(int i = -100;i<=100;i++){
				cnt = max(cnt,check(a[i]));
			}
			cout<<cnt;
		}
		else{
			int c=0;
			for(int i = 1;i<=n;i++){
				if(m>=a[i])c++;
				else break;
			}
			cout<<check(a[c]);
		}
		return 0;
	}
	sort(a+1,a+n+1);
	long long l = 0,r = n,mid = 0;
	int cnt = 0;
	for(int i = 1;i<=n;i++){
		cnt = max(cnt,check(a[i]));
	}
	cout<<cnt;
	return 0;
}
