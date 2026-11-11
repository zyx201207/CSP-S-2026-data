#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],t[300005],f=1,s;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]&&i>1)f=0;
	}
	if(f){
		for(int i=1;i<=n;i++){
			t[a[i]]++;
		}
		for(int i=1;i<=m;i++){
			s+=t[i];
			cout<<s<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		int l=0,s[505];
		memset(s,0,sizeof s);
		for(int j=i;j<=n;j++){
			int k=a[j],p=l+1;
			for(int o=1;o<=l;o++){
				if(s[o]==k){
					p=o;
					break;
				}
			}
			l=p-1;
			s[++l]=k;
		}
		for(int j=1;j<=l;j++){
			t[s[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
}
