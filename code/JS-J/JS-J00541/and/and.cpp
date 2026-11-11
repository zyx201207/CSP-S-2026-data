#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010];
int sum[50],ans=2147483647;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=a[i],l=0;
		while(x>0){
			sum[++l]+=(x&1);
			x>>=1;
		}
	}
	sort(a+1,a+n+1,cmp);
	int il;
	for(int i=30;i>=1;i--)
		if(sum[i]>=m){
			il=i;
			break;
		}
	for(int i=1;i<=n&&m>0;i++)
		if((a[i]&(1<<(il-1)))==(1<<(il-1))){
			ans&=a[i];
			m--;
		}
	cout<<ans;
	return 0;
}