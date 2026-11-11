#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=2e5+2;
char a[MAXN];
int num[MAXN];
int n;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int summ=0;
	for (int i=1;i<=n;i++){
		cin>>num[i]>>a[i];
		summ+=num[i];
	}
	int lpos=1,rpos=n,lsum=num[1],rsum=num[n];
	int i=1;
	int ans=0;
	int q=(summ+1)/2;
	//cout<<i<<' '<<q;
	while (i<=q){
		if (lsum>=i&&rsum>=i){
			if (a[lpos]!=a[rpos]){
				//cout<<lpos<<' '<<rpos<<' '<<i<<endl;
				//cout<<lsum<<' '<<rsum<<' '<<i<<endl;
				ans+=abs(min(lsum-i,rsum-i))+1;
				i+=min(lsum-i,rsum-i)+1;
			}
			if (a[lpos]==a[rpos]){
				i+=min(lsum-i,rsum-i)+1;
			}
		}
		else{
			if (lsum<i){
				lpos++;
				lsum+=num[lpos];
			}
			if (rsum<i){
				rpos--;
				rsum+=num[rpos];
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
	
