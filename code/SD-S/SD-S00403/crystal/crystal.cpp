#include<bits/stdc++.h>
#include<fstream>
using namespace std;
int main(){
	ifstream intputFile("crystal.in");
	long long n,m,ans=0,a[100010],b,leicha=0,d=0;
	intputFile>>n>>m;
	for(long long i=0;i<n;i++){
		intputFile>>a[i];	
	}
	sort(a-1,a+n);
	b=a[1];
	while(b<=a[n-1]){
		long long j=0;
		while(a[j]<=b){
			if(leicha+b-a[j]<=m&&a[j]<=b){
				leicha+=b-a[j];
				ans++;
			}
			j++;
		}
		b++;
		d=max(ans,d);
		ans=0;
		leicha=0;
	}
	ofstream outputFile("crystal.out");
	outputFile<<d;
	return 0;
} 
