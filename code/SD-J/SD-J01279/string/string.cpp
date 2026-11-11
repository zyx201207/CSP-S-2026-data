#include<bits/stdc++.h>
using namespace std;

long long a[200001];
char c[200001];
long long b[200001];
char d[200001];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
	}
//	int m=0;
//	for(int i=1;i<=n;i++){
//		if(c[i]!=d[m]){
//			b[++m]=a[i];
//			d[m]=c[i];
//		}else{
//			b[m]+=a[i];
//		}
//	}
	//for(int i=1;i<=m;i++)cout << b[i] << " " << d[i] << '\n';cout << '\n';//jjjjj
	int l=1,r=n;
	long long ans=0;
	while(l>=1&&r<=n&&l<=r){
		if(l==r)break;
		int x=min(a[l],a[r]);
		//cout << l << " " << r << " ";//
		if(c[l]!=c[r])ans+=x;
		a[l]-=x;
		a[r]-=x;
		//cout << b[l] << " " << b[r] << '\n';//
		if(a[l]==0)l++;
		if(a[r]==0)r--;
	}
	cout << ans;
	
	return 0;
}
