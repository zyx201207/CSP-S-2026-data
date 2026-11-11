#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005],t[1000005],s[1000005],top,ans[1000005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int k=1;k<=n;k++){
		top=0;
		for(int i=1;i<=n;i++)t[a[i]]=s[i]=0;
//		cout<<k<<":"<<'\n';
		for(int i=k;i<=n;i++){
			if(!t[a[i]]||t[a[i]]>=top){
				t[a[i]]=++top;
				s[top]=a[i];
			}else{
				top=t[a[i]];
				
			}
//			for(int j=1;j<=n;j++)cout<<s[j]<<" ";
//			cout<<"top:"<<top;
//			cout<<'\n';
		}
		for(int i=1;i<=top;i++)ans[s[i]]++;
//		cout<<'\n';
		
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}

