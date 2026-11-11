#include<bits/stdc++.h>
using namespace std;
long long n,b,ans[200010],l[1000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>b;
	for(int i = 1;i<=n;i++){
		cin>>ans[i];
	}
	sort(ans+1,ans+1+n);
	int cnt=1;
	for(int i = 1;i<=n;i++){
		if(ans[i]==ans[i+1]){
			l[cnt]=ans[i+1];
			cnt++;
		}
	}
	sort(l+1,l+cnt+1);
	//for(int i = 1;i<=n;i++){
	////	cout<<l[i]<<" ";
	//}
	cout<<ans[n];
	return 0;
}
