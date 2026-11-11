#include <bits/stdc++.h>
#include <windows.h>
#define int long long
#define endl "" 
using namespace std;
const int N=5e5+10;
int l=1,r=0;
int a[N],c[N];
int n,m;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	//还有 
//	//X X XXX
//	//O O OOO
//	//环节
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//cout << "OK";
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+(n+1),cmp);
	int times=0,ans=0;
//	for(int i=1;i<=n;i++){
//		cout << a[i] << " ";
//	}
	cout << endl;
	for(int i=1;i<n;i++){
		c[i]=a[i]-a[i+1];
		c[i+n]=c[n]=0x3f3f3f3f3f3f3f3fll;
		//cout << c[i] << " ";
	}
	//cout << endl;
	for(int l=1;l<n;l++){
		while(times<=m&&r<=n){
			times+=a[l]-a[++r];
			//printf("%d,%d,%d ",a[r-1],a[l],times);
			//Sleep(50);
		}
		ans=max(ans,r-l);
		//cout << l << " " << r << " " ;
		times-=c[l]*(r-l);
		//cout << times;
		//cout << endl;
		//cout << l << endl;
		//cout << " " <<  c[l]*(r-l) << endl;
	}
	cout << ans;
	//noting be like with you lala with you↓ 
	return 0;
} 
