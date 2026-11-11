#include<bits/stdc++.h>
using namespace std;
/*
RP++RP++RP++RP++RP++
RP++RP++RP++RP++RP++
RP++RP++RP++RP++RP++
RP++RP++RP++RP++RP++
RP++RP++RP++RP++RP++
*/
const int N=2e5+5;
int n,a[N],m;
map<int,int>mp;
bool cmp(int a,int b){
	return a>b;
}
//string jz(int x){
//	string s;
//	while(x>0){
//		s+=x%2+'0';
//		x/=2;
//	}string s2;int len=s.size();
//	for(int i=0;i>=len-1)
//	return s;
//}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	if(m==n){
		int sum=a[1];
		for(int i=2;i<=n;i++)sum=(sum&a[i]);
		cout<<sum;
		return 0;
	}if(m==1){
		sort(a+1,a+n+1,cmp);
		cout<<a[1];
		return 0;
	}else {
		sort(a+1,a+n=1,cmp);
		int sum=a[1];
		for(int i=2;i<=m;i++)
			sum=(sum&a[i]);
		cout<<sum;
	}
	return 0;
}
