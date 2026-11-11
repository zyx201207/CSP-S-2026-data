#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long int n,m,a[N],T[N],ans=-1;
int main(){
	freopen("ans.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		T[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		if(T[a[i]]>1){
			ans=a[i];
			break;
		}
		else ans=max(ans,a[i]);
	}
	cout<<ans;
	return 0;
}
