#include<bits/stdc++.h>
using namespace std;
int n,lft,rght,a[200010];
char c[200010];
string s;
long long ans,sum,l[200010],r[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	if(sum<=100000){
		//48`(12/25)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=a[i];j++)
				s+=c[i];
		for(int i=0;i<s.size()/2;i++)
			if(s[i]!=s[s.size()-i-1])
				ans++;
		cout<<ans;
	}
	else{
		//52`(13/25)
		for(int i=1;i<=n;i++){
			l[i]=r[i-1]+1;
			r[i]=l[i]+a[i]-1;
		}
		for(int i=1;i<=n;i++){
			int indxl=upper_bound(l+1,l+1+n,sum-l[i]+1)-l-1,indxr=upper_bound(l+1,l+1+n,sum-r[i]+1)-l-1;
			if(indxl<=i)
				break;
			for(int j=indxr;j<=indxl;j++)
				if(c[j]!=c[i])
					ans+=max(0ll,min(r[j],sum-l[i]+1)-max(l[j],sum-r[i]+1)+1);
		}
		cout<<ans;
	}
	return 0;
}
