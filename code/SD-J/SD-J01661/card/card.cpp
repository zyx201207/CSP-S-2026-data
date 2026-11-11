#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[200005],s[200005],f=0,ans[300005],ans1[300005];
bool t[300005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		f=0;
		for(int j=i;j<=n;j++){
			if(t[a[j]]==0){
				s[++f]=a[j];
				t[a[j]]=1;
			}
			else{
				while(f>0&&s[f]!=a[j]){
					t[s[f]]=0;
					f--;
				}
			}
		}
		while(f>0){
			if(ans[s[f]]==ans1[s[f]]){
				ans[s[f]]++;
			}
			t[s[f]]=0;
			f--;
		}
		for(int i=1;i<=m;i++){
			ans1[i]=ans[i];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
