#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],sum=0;
char b[200010];
long long li,ri;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	li=1;ri=n;
	while(li<ri){
		long long minn=min(a[li],a[ri]);
		if(b[li]!=b[ri])sum+=minn;
		a[li]-=minn;if(a[li]==0)li++;
		a[ri]-=minn;if(a[ri]==0)ri--;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
