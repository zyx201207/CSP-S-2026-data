#include<bits/stdc++.h>
using namespace std;
long long a[200001],s[200001];
int n,m;
long long ans=-1;
int cnt[200001];
int b[200001];
long long kkk=-1;
bool flag=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>4) flag=0;
		cnt[a[i]]++;
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<a[1];
		return 0;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans;
		return 0;
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}else if(m==n-1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i) continue;
				if(kkk==-1){
					kkk=a[i];
				}else{
					kkk&=a[i];
				}
			}
			ans=max(ans,kkk);
		}
		cout<<ans;
		return 0;
	}else if(flag==1){
		if(cnt[4]>=m){
			cout<<4;
			return 0;
		}else if(cnt[3]>=m){
			cout<<3;
			return 0;
		}else if((cnt[2]+cnt[3])>=m){
			cout<<2;
			return 0;
		}else if((cnt[1]+cnt[3])>=m){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}else{
		cout<<a[m];
		return 0;
	}
	return 0;
}