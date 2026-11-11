#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m,c;
	int flag1=1,flag2=1,flag3=1;
	cin>>n>>m;
	vector<long long> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==2) c=a[i]-a[i-1];
		if(a[i]-a[i-1]!=c&&i!=1) flag3=0;
		if(a[i]>100) flag1=0;
		if(a[i]!=i)	flag2=0;
	}
	if(n<=5000){
		sort(a.begin(),a.end());
		long long ma=1;
		for(int i=2;i<=n;i++){
			long long s=m,ans=1;
			int l=i-1,r=i;
			while(s>0&&l>0&&r<=n){
				while(a[l]==a[i]){
					ans++;
					l--;
				}while(a[r]==a[i]&&r!=i){
					ans++;
					r++;
				}s-=a[i]-a[l];
				ans++;
				l--;
			}
			if(s<0) ans--;
			ma=max(ma,ans);
		}
		cout<<ma;
	}else if(flag1){
		map<int,long long> cnt;
		for(int i=1;i<=n;i++){
			cnt[a[i]]++;
		}
		a.erase(unique(a.begin(),a.end()),a.end());	
		int id=unique(a.begin(),a.end())-a.begin()-2;
		long long ma=cnt[a[1]];
		for(int i=2;i<=id;i++){
			long long s=m,ans=cnt[a[i]];
			for(int j=i-1;j>=1;j--){
				if(s>=cnt[a[j]]*(a[i]-a[j])){
					s-=cnt[a[j]]*(a[i]-a[j]);
					ans+=cnt[a[j]];
				}else if(s>=a[i]-a[j]){
					long long b=s/(a[i]-a[j]);
					s-=b*(a[i]-a[j]);
					ans+=b;
				}
			}
			ma=max(ma,ans);
		}
		cout<<ma;
	}else 
	if(flag2){
		int ma=0;
		for(int i=1;i<=n;i++){
			if((i*i-i)/2<=m){
				ma=max(ma,i);
			}
		}
		cout<<ma;
	}else
	 if(flag3){
		int ma=0;
		for(int i=1;i<=n;i++){
			if((a[i]*i-a[i])/2<=m){
				ma=max(ma,i);
			}
		}
		cout<<ma;
	}else{
		cout<<m/c+1;
	}
	return 0;
} 
