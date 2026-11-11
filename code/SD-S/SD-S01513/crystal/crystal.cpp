#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+100;
int s[N],a[N],ch[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	if(m>=(a[n]-a[1])*n){
		cout<<n;
		return 0; 
	}int c=a[2]-a[1],l=0;
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=c){
			l=1;
			break;
		}
	}if(l==0){
		int maxx=1;
		for(int i=2;i<=n;i++){
			int o=i-1;
			int x=(o+1)*o/2*c;
			if(m>=x){
				maxx=max(maxx,i);
			}
		}cout<<maxx;
		return 0;
	}for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		ch[i]=ch[i-1]+(a[i]-a[i-1]);
	}int maxx=1;
	for(int i=2;i<=n;i++){
		int sum=0,cnt=i;
		for(int j=i-1;j>=1;j--){
			sum+=ch[i-1]-ch[--cnt];
			if(m>=sum){
				maxx=max(maxx,i-cnt);
			}
		}
	}cout<<maxx;
	return 0;
}
