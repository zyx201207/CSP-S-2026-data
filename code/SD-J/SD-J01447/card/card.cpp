#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],s[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[a[i]]=i;
	} 
	for(int i=1;i<=n;i++){
		int j=i;
		ans[a[i]]++;
		while(j<n){
			j=s[a[j]];
			j++;
			ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} //记忆化搜索怎么写呀！！！呜呜呜，都想出正解了~~~~ 
