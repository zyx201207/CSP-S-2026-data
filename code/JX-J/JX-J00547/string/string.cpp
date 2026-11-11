#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long cnt=0;
	long long n;
	char q1;
	char q2;
	long long a[200005];
	char c[200005];
	long long sum=0;
	long long k=0;
	long long ans;
	cin>>n;
	long long a_i1=0;
	long long a_i2=n-1;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	if(sum%2)ans=(sum-1)/2;
	else ans=sum/2;
	while(k<ans){
		k++;
		q1=c[a_i1];
		a[a_i1]--;
		if(a[a_i1]==0)a_i1++;
		q2=c[a_i2];
		a[a_i2]--;
		if(a[a_i2]==0)a_i2--;
		if(q1!=q2)cnt++;
	}
	cout<<cnt;
	return 0;
}
