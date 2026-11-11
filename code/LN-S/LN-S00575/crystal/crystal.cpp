#include <bits/stdc++.h>
using namespace std;
long long a[500005],Max;
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	bool flag=0,flag0=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=2;i<=n;i++){
		if(a[i]!=a[i-1]){
			flag=1;
			break;
		}
	}
	long long ch=a[2]-a[1];
	for(long long i=3;i<=n;i++){
		if(a[i]-a[i-1]!=ch){
			flag0=1;
			break;
		}
	}
	if(flag==0){
		cout<<n;
		return 0;
	}
	if(flag0==0){
		long long h=0,q=1;
		while(1){
			if((h+ch*q)<=m){
				h+=ch*q;
				q++;
			}else{
				break;
			}
		}
		cout<<q;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	for(long long i=1;i<=n;i++){
		long long sum=0,ans=1;
		for(long long j=i-1;j>=1;j--){
			sum+=a[i]-a[j];
			if(sum>m){
				break;
			}else{
				ans++;
				Max=max(ans,Max);
			}
		}
	}
	cout<<Max;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
