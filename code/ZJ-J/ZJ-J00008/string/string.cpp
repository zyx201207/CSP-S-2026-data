#include <bits/stdc++.h>
using namespace std;
long long n,a[2000005],ans;
char ch[2000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i]>>ch[i];
	int l=1,r=n;
	while(l<r){
		if(a[l]<a[r]){
			if(ch[l]!=ch[r]) ans+=a[l];
			a[r]-=a[l];
			l++;
		}else if(a[l]==a[r]){
			if(ch[l]!=ch[r]) ans+=a[l];
			l++,r--;
		}else{
			if(ch[l]!=ch[r]) ans+=a[r];
			a[l]-=a[r];
			r--;
		}
	}
	cout<<ans;
	return 0;
}
