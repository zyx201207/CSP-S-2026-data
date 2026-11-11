#include<bits/stdc++.h>

using namespace std;
int n;
long long a[1000000],sa[1000000];
long long k=LLONG_MIN,c;
map<long long,long long> m;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long e;
	cin >> n>>e;
	int h=0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		m[a[i]]++;
		k=max(k,a[i]);
		if(m[a[i]]==1){
			sa[h]=a[i];
			h++;
		}
	}
	for(int i=0;i<n;i++){
		c+=(k-a[i]);
	}
	long long ans=n;
	sort(sa,sa+h,cmp);
	for(int i=0;i<h;i++){
		if(c<=e){
			break;
		}
		ans-=m[sa[i]];
		c-=ans*(sa[i]-sa[i+1]);
	}
	cout << ans;
	return 0; 
}
