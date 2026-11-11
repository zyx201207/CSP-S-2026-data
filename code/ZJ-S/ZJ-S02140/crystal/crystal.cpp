#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cnt=0,ans=0,s[500005],q[5005][5005];
long long minn=1e12+5,mix=0;
long long p[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int t=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1){
			if(a[i]!=a[i-1]){
				t=1;
			}
			
		}
	}
	if(t==0){
		cout<<n;
		return 0;
	}
	sort(a+1,a+1+n);
	
	for(int i=2;i<=n;i++){
		s[i]=abs(a[i]-a[i-1]);
	}
	t=0;
	for(int i=3;i<=n;i++){
		if(s[i]!=s[i-1]){
			t=1;
		}
	}
	for(int i=1;i<=n;i++){
		p[i]=p[i-1]+i;
	}
	if(t==0){
		t=s[3];
		for(int i=1;i<=n;i++){
			if(p[i]*t<=m){
				cnt=i;
			}else{
				break;
			}
		}
		cout<<cnt+1;
		return 0;
	}
	while(1){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				q[i][j]=q[j][i]=abs(a[i]-a[j]);
				if(minn>q[i][j]&&q[i][j]!=0){
					minn=q[i][j];
					mix=i;
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				cout<<q[i][j];
//			}
//			cout<<"\n";
//		}
//		cout<<minn<<" "<<mix;
		if(ans+minn<=m){
			a[mix]+=minn;
			ans+=minn;
			cnt++;
		}else{
			if(cnt==0){
				cnt=1;
			}
			cout<<cnt;
			return 0;
		} 
	} 
	return 0;
}//4 9 -3 1 4 7