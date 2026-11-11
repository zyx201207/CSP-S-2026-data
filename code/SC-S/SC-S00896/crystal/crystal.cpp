#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100001],s=1;
long long aaa(long long p){
	for(long long i=0;i<n;i++){
		if(a[i]<=p&&a[i+1]>p)return i;
	}
}
int main()
{
	freopen(crystal.in,"r",stdin);
	freopen(crystal.out,"w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(long long i=a[0];i<=a[n-1];i++){
		cout<<i<<"   ";
		long long t=0,m1=m;
		for(long long j=aaa(i);j>=0;j--){
			if(a[j]==i)t++;
			else {
				if(i>a[j]&&i-a[j]<=m1&&m1>0){
					m1=m1-i+a[j];
					t++;
				}
			}
		}
		if(s<t)s=t;
	}
	cout<<s;
	return 0;
} 