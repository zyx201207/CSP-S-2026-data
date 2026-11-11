//Kong Chenfeng xi'an shi han guang zhong xue SN-J00666
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=2e5+5;
int a[maxn],pw[maxn];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	pw[0]=1;
	for(int i=1;i<=30;i++){
		pw[i]=pw[i-1]*i;
	}
	int n,m;
	cin>>n>>m;

	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt2+=(a[i]==i-1?1:0);
		for(int i=30;i>=0;i++){
			if(a[i]=pw[i]-1){
				cnt1++;
				break;
			}
		}
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<0<<endl;
		return 0;
	}
	if(m==2){
		int maxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx<<endl;
		return 0;
	}
	if(m==n){
		int sum=a[1];
		for(int i=2;i<=n;i++){
			sum&=a[i];
		}
		cout<<sum<<endl;
		return 0;
	}
	if(cnt1==n||cnt2==n){
		cout<<a[n-m+1]<<endl;
		return 0;
	}
	return 0;
}

