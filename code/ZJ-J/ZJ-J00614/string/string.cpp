#include<bits/stdc++.h>
#define int long long
using namespace std;
struct asd{
	char c;
	int a;
};
int n,len,mid;
asd a[200010],b[200010];
int ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
		b[n-i+1].a=a[i].a;
		b[n-i+1].c=a[i].c;
		len+=a[i].a;
	}
	int suml=0,sumr=0,cntl=0,cntr=0;
	char zl,zr;
	mid=(len+1)/2;
	for(int i=1;i<=mid;i++){
		if(suml<i){
			cntl++;
			suml+=a[cntl].a;
			zl=a[cntl].c;
		}if(sumr<i){
			cntr++;
			sumr+=b[cntr].a;
			zr=b[cntr].c;
		}
		if(zr!=zl){
			ans++;
		}
	}cout<<ans;
	return 0;
}

