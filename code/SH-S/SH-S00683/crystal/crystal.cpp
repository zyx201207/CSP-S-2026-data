#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
inline int max(int x,int y){
	if(x>y)return x;
	else return y;
} 
const int N=5000000+5;
int a[N],b[N];
ull cha[N],cha2[N];
signed main(){
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ull n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m>500000){
		for(int i=1;i<=n;i++){
		cha[i]=(a[i]-a[i-1])*(i-1)+cha[i-1];
		cha2[i]=a[i]-a[i-1];
	}
	int i;
	for(i=1;i<=n&&cha[i]<=m;i++);
	cout<<i-1;
	return 0;
}

	int ans=0;
	for(int i=n;i>=1;i--){
		int k=0,anss=1;
		for(int j=i-1;j>=1;j--){
			k+=a[i]-a[j];
			if(k>m)break;
			else anss++;
		}
		ans=max(ans,anss);
	}
	cout<<ans;
	return 0;
}
