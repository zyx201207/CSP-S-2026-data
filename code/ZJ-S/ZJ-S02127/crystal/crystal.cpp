#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m,a[N],c[N],ans,mm,anss;
bool flag=true;
long long add(long long st,long long end){
	long long sum=0;
	for(int i=st+1;i<=end;i++)sum+=c[i];
	return sum;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	c[2]=a[2]-a[1];
	for(int i=3;i<=n;i++){
		c[i]=a[i]-a[i-1];
		if(c[i]!=c[i-1])flag=false;
	}
	if(flag){
		for(int i=1;;i++){
			if(c[2]*i*(i+1)/2>m){
				cout<<i-1;
				break;
			}
		}
	}else{
		for(int i=2;i<=n;i++){
			long long mm=0,j=i-1,anss=1;
			while(mm<m&&j>=1)if(mm+add(j,i)<=m){
				mm+=add(j,i);
				anss++;
				j--;
			}else break;
			ans=max(ans,anss);
		}
		cout<<ans;
	}
	return 0;
}
