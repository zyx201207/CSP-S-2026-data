#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,cnt,cnt1,f,f1,f11;
long long m,ans,num;
long long a[N],b[N],ans1[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			f=1;
		}
	}
	f1=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=f1){
			f11=1;
			break;
		}
	}
	if(f1==0){
		while(m>0){
			cnt+=f1;
			m-=cnt;
			ans++;
		}
		if(m==0){
			cout<<(ans-1ll*1);
			return 0;
		}
		cout<<ans;
		return 0;
	}
	if(f==0){
		while(m>0){
			cnt++;
			m-=cnt;
			ans++;
		}
		if(m==0){
			cout<<(ans-1ll*1);
			return 0;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	for(int i=1;i<n;i++){
		num=0,cnt=i+1;
		while(num<=m&&cnt<=n){
			num+=b[cnt]*(cnt-i);
			ans1[i]++;
			cnt++;
		}
	}
	for(int i=1;i<n;i++){
		ans=max(ans,ans1[i]);
	}
	cout<<ans;
	return 0;
}
