#include<bits/stdc++.h>
#define int long long
#define N 200005
using namespace std;
int n;
int a[N];
char b[N];
int ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int j=n,i=1;
	while(1){
		//cout<<b[i]<<' '<<b[j]<<'\n';
		if(i>=j)break;
		if(b[i]!=b[j])ans+=min(a[i],a[j]);
		if(a[i]==a[j]){i++;j--;}
		else if(a[i]>a[j]){a[i]-=a[j];j--;}
		else{a[j]-=a[i];i++;}
	}
	cout<<ans;
	return 0;
}
