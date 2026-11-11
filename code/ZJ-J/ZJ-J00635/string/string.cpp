#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005];
char ch[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>ch[i];
	int l=1,r=n,suml=0,sumr=0,s=0,ans=0;
	while(l<r){
		if(suml+a[l]<sumr+a[r]){
			int x=suml+a[l]-s;
			if(ch[l]!=ch[r]) ans+=x;
			s+=x;
			suml+=a[l],l++;
		}
		else if(suml+a[l]>sumr+a[r]){
			int x=sumr+a[r]-s;
			if(ch[l]!=ch[r]) ans+=x;
			s+=x;
			sumr+=a[r],r--;
		}
		else{
			int x=suml+a[l]-s;
			if(ch[l]!=ch[r]) ans+=x;
			s+=x;
			suml+=a[l],sumr+=a[r];
			l++,r--;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
