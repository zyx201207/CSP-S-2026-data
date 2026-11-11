#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	long n;
	long long m;
	cin>>n>>m;
	long a[n];
	for(long i=0;i<n;i++)
		cin>>a[i];
	for(long i=0;i<n-1;i++)
		for(long j=0;j<n-i;j++)
			if(a[j]<a[j-1])
				swap(a[j],a[j-1]);
	long max=LONG_MIN;
	while(m!=0){
		a[0]++;
		m--;
		for(long i=0;i<n-1;i+=1)
			for(long j=0;j<n-i;j+=1)
				if(a[j]<a[j-1])
					swap(a[j],a[j-1]);
		long cnt=1,m=LONG_MIN;
		for(long i=0;i<n-1;i+=1){
			if(a[i]==a[i+1])
				cnt++;
			else{
				if(cnt>m){
					m=cnt;
					cnt=1;
				}
			}
		}
		if(m>max)
			max=m;
	}
	cout<<max;
	return 0;
}

