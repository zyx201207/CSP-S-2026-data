#include<bits/stdc++.h>
using namespace std;
long long a[500010],e[500010],n,m,l,r,s=0,sum=0,flag=0,ans,cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	l=n;r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) flag=1;
	}
	sort(a+1,a+n+1);
	if(flag==0){
		while(s<=m){
			sum++;
			s+=sum;
		}
		s-=sum;
		cout<<sum;
		return 0;
	}
	flag=0;
	e[1]=a[2]-a[1];
	for(int i=2;i<n;i++){
		e[i]=a[i+1]-a[i];
		if(e[i]!=e[i-1]) flag=1;
	}
	if(flag==0){
		int len=e[1];
		while(s<=m){
			sum++;
			s+=sum*len;
		}
		s-=sum*len;
		cout<<sum;
		return 0;
	}
	for(int i=n;i>=1;i--){
		cnt++;
		for(int j=r;j>l;j--){
			sum+=e[j];
		}
		while(sum>m){
			sum-=e[r]*(cnt-1);
			for(int i=1;i<r;i++){
				e[i]-=e[r];
			}
			r--;
			cnt--;
		}
		ans=max(ans,cnt);
		l--;
	}
	cout<<ans;
	return 0;
}
