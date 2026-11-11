//朱毅然 陕西延安中学 SN-S00362
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		if((a[i+1]-a[i])*i<=m){
			m-=a[i+1]-a[i];
			ans++;
		}else break;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
