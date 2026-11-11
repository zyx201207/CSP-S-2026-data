#include<bits/stdc++.h>
using namespace std;
int n,a[200010];
int cnt[30];
char c[200010];
int ans;
int cmt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cnt[c[i]-'a'+1]+=a[i];
	}
	int l=1,r=n;
	while(l<r){
		if(cnt[c[l]-'a'+1]>cnt[c[r]-'a'+1]){
			ans+=a[r];
			cnt[c[r]-'a'+1]-=a[r];
			cnt[c[l]-'a'+1]+=a[r];
			cmt=a[l]-a[r];
		}
		if(cnt[c[l]-'a'+1]<cnt[c[r]-'a'+1]){
			ans+=a[l];
			cnt[c[l]-'a'+1]-=a[l];
			cnt[c[r]-'a'+1]+=a[l];
			cmt=a[r]-a[l];
		}
		l++;
		r--;
		if(cnt[c[l]-'a'+1]==cnt[c[r]-'a'+1]){
			ans+=cmt;
		}
	}
	
	cout<<ans;
	return 0;
}
