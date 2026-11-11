#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005],s[500005];
int find1(int n,long long m){
	int l=1,r=n,ans=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[mid]<=m){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	return ans;
}
int find2(int id,long long m,long long up){
	int l=1,r=id,ans=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(up*(id-mid+1)-(s[id]-s[mid-1])<=m){
			ans=mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	return ans;
}
long long check1(int n,long long limit,long long use){
	int cnt=1;
	for(int i=n;i>=1;i--){
		b[i]=a[i];
		if(use<=a[i]){
			continue;
		}
		if(limit-(use-a[i])>=0){
			limit-=(use-a[i]);
			b[i]=use;
		}else{
			break;
		}
	}
	int maxi=1;
	for(int i=1;i<=n;i++){
		if(b[i]!=b[i+1]){
			maxi=max(maxi,cnt);
			cnt=1;
		}else{
			cnt++;
		}
	}
	//cout<<use<<":\n";
	/*for(int i=1;i<=n;i++){
		cout<<b[i]<<" ";
	}
	cout<<":"<<max(maxi,1)<<"\n";*/
	return max(maxi,1);
}
long long check(int n,long long limit,long long use){
	/*for(int i=n;i>=1;i--){
		b[i]=a[i];
		if(use<=a[i]){
			continue;
		}
		if(limit-(use-a[i])>=0){
			limit-=(use-a[i]);
			b[i]=use;
		}else{
			break;
		}
	}*/
	int r=find1(n,use);
	int l=find2(r,limit,use);
	//cout<<use<<":\n";
	/*for(int i=1;i<=n;i++){
		cout<<b[i]<<" ";
	}
	cout<<":"<<max(maxi,1)<<"\n";*/
	return max(r-l+1,1);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long m;
	cin>>n>>m;
	long long up=-1e18;
	long long down=1e18;
	bool is=1;
	bool is2=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
		up=max(up,a[i]);
		down=min(down,a[i]);
		is&=(a[i]==1ll*i);
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		is2&=(a[i-1]-a[i-2]==a[i]-a[i-1]);
	}
	if(is2){
		long long diff=a[2]-a[1];
		int cnt=1;
		for(int i=1;i<=n-1;i++){
			if(m-diff*i>=0){
				m-=diff*i;
				cnt++;
			}else{
				break;
			}
		}
		cout<<cnt;
		return 0;
	}
	if(is){
		int cnt=1;
		for(int i=1;i<=n-1;i++){
			if(m-i>=0){
				m-=i;
				cnt++;
			}else{
				break;
			}
		}
		cout<<cnt;
		return 0;
	}
	if(n<=500005 && up<=100 && down>=-100){
		long long maxi=1;
		for(long long i=down;i<=up;i++){
			maxi=max(maxi,check1(n,m,i));
		}
		cout<<maxi;
		return 0;
	}
	long long maxi=1;
	for(long long i=down;i<=up;i++){
		maxi=max(maxi,check(n,m,i));
	}
	cout<<maxi;
	return 0;
}
