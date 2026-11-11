#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,sum[N],m=1;
char word[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int lsum;
	char lword;
	cin>>lsum>>lword;
	sum[m]=lsum;
	word[m]=lword;
	for(int i=2;i<=n;++i){
		int nsum;
		char nword;
		cin>>nsum>>nword;
		if(nword==lword){
			sum[m]+=nsum;
		}else{
			sum[++m]=nsum;
			word[m]=nword;
		}
		lword=nword;
		lsum=nsum;
	}
	int l=1,r=m,ans=0;
	while(l<=r){
		int tmp=min(sum[l],sum[r]);
		sum[l]-=tmp;
		if(l!=r)sum[r]-=tmp;
		if(word[l]!=word[r]){
			ans+=tmp;
		}
		if(!sum[l])++l;
		if(!sum[r])--r;
	}
	cout<<ans;
	return 0;
}