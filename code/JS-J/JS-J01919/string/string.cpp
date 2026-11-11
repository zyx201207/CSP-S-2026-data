#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	c[0]='A';
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int cnt=1;
	for(int i=2;i<=n;i++){
		if(c[i]==c[cnt]){
			a[cnt]+=a[i];
		}else{
			cnt++;
			a[cnt]=a[i];
			c[cnt]=c[i];
		}
	}
	if(cnt==1){
		cout<<0;
		return 0;
	}
	int l=1;
	int r=cnt;
	long long ans=0;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else if(a[r]>a[l]){
				a[r]-=a[l];
				l++;
			}else{
				l++;
				r--;
			}
		}else if(a[l]>a[r]){
			a[l]-=a[r];
			ans+=a[r];
			r--;
		}else if(a[r]>a[l]){
			a[r]-=a[l];
			ans+=a[l];
			l++;
		}else{
			ans+=a[l];
			l++;
			r--;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
