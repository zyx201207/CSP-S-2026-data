#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000005],cnt,sum,ch[1000005],maxx=-1e17,mch,flag=1,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<n;i++){
		if(a[i]-a[i-1]!=a[i+1]-a[i]){
			flag=0;
		}
	}
	if(flag){
		cout<<m/(a[2]-a[1])+1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		ch[i]=a[i+1]-a[i];
	}
	for(int i=1,j=1;i<=n;i++){
		sum+=ch[i-1]*(i-1);
		mch+=ch[i-1];
		ans++;
		while(sum>m){
			sum-=mch;
			mch-=ch[j++];
			ans--;
			if(sum<=m||ans<=0){
				break;
			}
		}
		maxx=max(maxx,ans);
	}
	cout<<max(maxx,cnt);
	return 0;
} 
