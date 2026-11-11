#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	long long sum=0,t=0;
	char b[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		sum+=a[i];
	}
	long long l=0,sum1=sum;
	char x,y;
	for(int i=0;i<sum/2;i++){
		if(i<a[l]){
			x=b[l];
		}
		else{
			l++;
			x=b[l];
		}
		if(sum-l>sum1-a[n-1]){
			y=b[n-1];
		}
		else{
			sum1-=a[n-1];
			n--;
			y=b[n-1];
		}
		if(x!=y) t++;
	}
	cout<<t;
	}
