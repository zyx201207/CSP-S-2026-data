#include <bits/stdc++.h>
using namespace std;
long long n,m,a[2*100005];
map <long long,long long> s;
bool cmp(int a,int b){
	if(s.count(a+1)!=s.count(b+1)) return s.count(a+1)>s.count(b+1);
	return a<b;
}
bool cmp2(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long x=1;
	for(int i=1;i<=1000005;i++){
		x*=2;
		s[x]=1;
	}
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!s.count(a[i]+1)){
			flag=0;
		}
	}
	sort(a+1,a+n+1,cmp2);
	if(flag){
		cout<<a[m];
		return 0;
	}
	long long cnt=0;
	sort(a+1,a+n+1,cmp);
	long long r=0;
	bool f=true;
	for(int i=1;i<=n+1;i++){
		if(s.count(a[i]+1)) cnt++;
		if(!s.count(a[i]+1)&&f){
			r=i-1;
			f=false;
		}
	}
	if(cnt>=m){
		cout<<a[r-m+1];
		return 0;
	}
	cout<<0;
	return 0;
} 
