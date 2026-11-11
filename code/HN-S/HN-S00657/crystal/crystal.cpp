#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,sum=0,s=0;
	cin>>n>>m;
	long long a[n],num=0;
	for(long long i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
 	}
	sum/=n;
	sort(a,a+n,cmp);
	num=a[n/2];
	for(long long i=0;i<n;i++){
		if(a[i]<=num){
			s++;
		}
	}
	cout<<s;
return 0;
}
