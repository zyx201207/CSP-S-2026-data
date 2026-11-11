#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int n;
ll m,a[N],cnt,sum,ans;
bool flag;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--){
		cnt=0;
		sum=0;
		while(a[i-1]==a[i]&&i-1>=1){
			i--;
			cnt++;
		}
		for(int j=i;j>=1;j--){
			cnt++;
			sum+=a[i]-a[j];
			if(sum>m){
				flag=1;
				cnt--;
				break;
			}
		}
		ans=max(ans,cnt);
		if(flag){
			break;
		}
		if(ans>=i){
			break;
		}
	}
	cout<<ans;
	return 0;
} 
