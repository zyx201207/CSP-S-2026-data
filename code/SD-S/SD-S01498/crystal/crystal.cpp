#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=1,mm=m,cnt=1,as=0;
	while(1){
		if(r==n) break;
		int next=a[r+1]-a[r];
		while(mm<next*cnt){
			if(l==r) break;
			l++;
			cnt--;
			mm+=a[l];
		}
		if(next*cnt<=mm){
			mm-=next*cnt;
			a[r]=next;
			cnt++;
			r++;
			as=max(cnt,as);
		}
		else{
			break;
		}
	}
	cout<<as;
	return 0;
}

