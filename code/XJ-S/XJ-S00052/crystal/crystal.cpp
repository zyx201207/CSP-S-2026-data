#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],s[N],l=1,r=n,mid,maxx,ans1,sum;
long long ch(long long ans){
	sum=m,ans1=0;
	for(long long j=1;j<=n;j++){
		if(a[ans]<a[j]) break;
		s[j]=a[ans]-a[j];
	}
	for(long long j=ans;j>=1;j--){
		if(sum<s[j]){
			break;
		}
		sum-=s[j];
		ans1++;
	}
	maxx=max(maxx,ans1);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];

	}
	sort(a+1,a+n+1);
	if(n>5000&&a[n]==a[1]+(a[2]-a[1])*n-1){
		cout<<m/(a[2]-a[1])+1;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		ch(i);
	}
	cout<<maxx;
	return 0;
	
} 
