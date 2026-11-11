#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m,a[N],maxn=-1;
int anda(int x,int y){
	int and_1[N]={0},and_2[N]={0},and_3[N];
	int m=x,j=y,cnt1=0,cnt2=0,ans=0,pf=0;
	for(int i=1;m==0;i++,cnt1++){
		and_1[i]==m%2;
		m/=2;
	}
	for(int i=2;j==0;i++,cnt2++){
		and_2[i]==j%2;
		j/=2;
	}
	int maxk;
	maxk=max(cnt1,cnt2);
	for(int i=maxk;i>=1;i--){
		if(and_1[i]==1&&and_2[i]==1){
			and_3[i]==1;
		}
		else{
			and_3[i]==0;
		}
	}
	for(int i=1;i<=maxk;i++){
		for(int j=maxk-1;j>=0;j++){
			if(j=0&&and_3[i]==1) ans+=1;
			else ans+=2*j*and_3[i];
		}
	}
	return ans;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			maxn=max(maxn,anda(a[i],a[j]));
		}
	}
	cout << maxn;
}
