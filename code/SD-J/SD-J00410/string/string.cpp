#include<bits/stdc++.h>
using namespace std;
const long long maxm=200000000000005;
long long n,a[200005],sum=0,id=1;
unsigned long long len=0;
char c[200005],ans[maxm];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
		for(long long j=id;j<=id+a[i];j++)
			ans[j]=c[i];
		id+=a[i];
	}
	for(long long i=1;i<=len/2;i++)
		if(ans[i]!=ans[len-i+1])
			sum++;
	cout<<sum<<endl;
	return 0;
}
