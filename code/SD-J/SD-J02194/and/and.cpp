#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int n,m;
int a[MAXN];
int ans=-1;
//int cnt;
//long long c[MAXN];
//int jinzhi(int x){
//	int a[MAXN*4];
//	int cnt=1;
//	while(x>1){
//		a[cnt]=x%2;
//		x/=2;
//		cnt++;
//		return a[cnt];
//	}
//}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
//		c[i]=int(jinzhi(a[i]));
	} 
	if(m==1) {
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}else if(m==2){
//		for(int i=1;i<n;i++){
//			for(int j=i+1;j<=n;j++){
//				cout<<(a[i] and a[j])<<" ";
//				cout<<endl;	
//				int x=a[i],y=a[j];
//				cout<<x and y;
//				cnt=x and y;
//				cout<<cnt<<"\n";
//				ans=max(cnt,ans);
//			}
//		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]==a[j])ans=max(a[i],ans);
			}
		}
		cout<<ans;
	}
	return 0;
}
