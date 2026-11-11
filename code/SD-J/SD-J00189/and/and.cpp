#include<bits/stdc++.h>
using namespace std;
const int maxn=1e8;
bool cmp(int a,int b){
	return a>b;
}
int a[maxn],cnt[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i]=x;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){	
		for(int j=1;j<=maxn;j++){
			cnt[i]=a[i]%2;
			a[i]%=2;
			if(a[i]/2==0){
				cnt[i]=1;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<cnt[i];
	}	
	return 0;
}
