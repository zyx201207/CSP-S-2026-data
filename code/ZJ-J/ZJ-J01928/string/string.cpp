#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],b[200005],f[30][200005],ans;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	char c;
	for(int i=1,x; i<=n; i++) {
		cin>>x>>c,a[i]=m+1,b[i]=c-'a'+1,m+=x;
		for(int j=1; j<=26; j++)
			f[j][i]=f[j][i-1];
		f[b[i]][i]+=x;
	}
	a[n+1]=m+1;
	for(int i=1,x,y; i<=n; i++) {
		x=a[i],y=a[i+1]-1;
		int l=1,r=n,s1,s2;
		while(l<=r) {
			int mid=(l+r)/2;
			if(a[mid]<=m-y+1)l=mid+1,s1=mid;
			else r=mid-1;
		}
//		i:a[i+1]-1;
		l=1,r=n;
		while(l<=r) {
			int mid=(l+r)/2;
			if(a[mid+1]-1>=m-x+1)r=mid-1,s2=mid;
			else l=mid+1;
		}
//		cout<<s1<<" "<<s2<<"\n";
//		s1:a[s1+1]-m+y-1;
//		s2:m-x+1-a[s2]+1;
//		s2-1-s1+1;
		if(s1==s2){
			if(b[s1]!=b[i])ans+=m-x+1-m+y;
			continue;
		}
		if(b[s1]!=b[i])ans+=a[s1+1]-m+y-1;
		if(b[s2]!=b[i])ans+=m-x+1-a[s2]+1;
		if(s2-s1==1)continue;
		ans+=a[s2]-a[s1+1]-f[b[i]][s2-1]+f[b[i]][s1];
	}
	cout<<ans/2<<"\n";
	return 0;
}