#include<bits/stdc++.h>
using namespace std;
long long n,a[100010],t,cnt=0;
long long s[100010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	char c;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c;
		t+=a[i];
		s[i]=c-'a';
	}
	for(long long l=1;l<=t/2;l++){
		long long r=t-l+1;
		long long i=1,j=t/2+1;
		long long sum1=a[i],sum2=a[j];
		while(a[l]>=sum1){
			i++;
			sum1+=a[i];
		}
		while(a[r]>=sum2){
			j++;
			sum2=sum2+a[j];
		}if(!(s[i]==s[j])) cnt++;
	}cout<<cnt;
	return 0;
}
