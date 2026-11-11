#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000001],l,r,nl,nr,s1,s2,s3,s4=1,s5=1,s6;
map<int,int> t;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	s1=1;
	s2=1;
	s3=0;
	l=1,r=1;
	for(int i=2;i<=n;i++){
		
		if(s3+s2*(a[i]-a[i-1])<=m){
			s2++;
			s1=max(s1,s2);
			s3=s3+(s2-1)*(a[i]-a[i-1]);
			r++;
//			cout<<s1<<" "<<s2<<" "<<s3<<" "<<l<<" "<<r<<" "<<i<<"\n";
			continue;
		}
		while(s3+s2*(a[i]-a[i-1])>m&&s2!=1){
			s3-=a[i-1]-a[l];
			s2--;
			l++;
		}
		s2++,r++;
		s3=s3+(s2-1)*(a[i]-a[i-1]);
		s1=max(s1,s2);
//		cout<<s1<<" "<<s2<<" "<<s3<<" "<<l<<" "<<r<<" "<<i<<"\n";
	}
	cout<<s1;
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7

5 100
-100 -10 0 10 100

10 100
-100 -100 -100 -100 -50 -50 -49 0 0 0

10 10
1 2 3 6 7 8 9 10 10 10
*/
