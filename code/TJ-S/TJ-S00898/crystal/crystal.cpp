#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500010],x,ans,cnt,c[500010],num,flag=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ans=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=ans)	flag=0;
	}
	if(flag){
		for(int i=1;i<=n;i++){
			m-=(i*ans);
			if(m<0){
			cout<<i; 
			break;
			}
		}
		return 0;
	}
	for(int i=2;i<=n;i++){
		c[i]=a[i]-a[i-1]; 
	}
	for(long long i=2;i<=n;i++){
		num=m;
		for(long long j=i;j>=1;j--){
			int f=m-num;			
			num-=(c[j]+f);
			if(num<0){
				cnt=max(cnt,i-j+1);
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
	//z
} 

