#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=1;
	int ans=0;
	for(int w=30;~w;w--){
		bool fl=0;
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(b[i]&&((a[i]>>w)&1))cnt++;
		}
		if(cnt>=m){
			ans+=(1<<w);
			for(int i=1;i<=n;i++){
				if(((a[i]>>w)&1)==0)b[i]=0;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
