#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m;
int a[maxn],ans;
bool cmp(int a,int b){return a<b;}
int main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=n;i>0;i--){
		int sum=0,j;
		for(j=i-1;j>0&&sum<=m;j--){
			sum+=a[i]-a[j];
		}
		ans=max(ans,i-j);
		if(j==0)break;
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
