#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500006];
long long cnt[500006];
bool f=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	long long bj;
	long long maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		if(i==1){
			bj=a[i];
		}
		if(a[i]<bj){
			f=0;
		}
		cnt[a[i]]++;
	}
	if(f){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=maxn;j++){
				if(cnt[j]>0){
					cout<<n<<" ";
				}
				else{
					cout<<0<<" ";
				}
			}
		}	
	}
	return 0;
}
