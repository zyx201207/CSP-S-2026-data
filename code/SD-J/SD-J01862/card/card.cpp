#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=1e6+5;
int n,m,a[N],t[N],ans[N],s[N],cnt;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			t[a[j]]++;
			s[++cnt]=a[j];
			if(t[a[j]]==2){
				s[cnt]=0;
				cnt--;
				while(s[cnt]!=a[j]&&cnt!=0){
					t[s[cnt]]--;
					s[cnt]=0;
					cnt--;
				}
				t[a[j]]--;
			}
		}
		while(cnt!=0){
			s[cnt]=0;
			cnt--;
		}
		for(int j=1;j<=m;j++){
			if(t[j]){
				ans[j]++;
			}
			t[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
