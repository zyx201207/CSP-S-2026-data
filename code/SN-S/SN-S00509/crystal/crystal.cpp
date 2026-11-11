//SN-S00509 李泽琛 西安交通大学附属中学
#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
int n,m,a[maxn],p[maxn],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		p[i] = a[i] - a[i-1];
	}
	int l=0;
	for(int i=0;i<n;i++){
		int len = i - l + 1;
		ans = max(len,ans);
		if(p[i+1]*len<=m){
			m-=p[i+1]*len;
		}
		else{
			while(p[i+1]*len>m&&l<=i+1){
				m += a[i]-a[l];
				l++,len--;	
			}
			m-=p[i+1]*len;
		}
	}
	cout << ans;
} 
