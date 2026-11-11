#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,zj,zi,ans;
struct no{
	long long y,l,r,sum;
	string x;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int wei=0;
	for(int i=1;i<=n;i++){
		long long x;
		string y;
		cin>>x>>y;
		a[i].x=y;a[i].l=wei;a[i].r=wei+x;a[i].sum=x;
		wei=a[i].r;
	}
	/*for(int i=1;i<=n;i++){
		cout<<a[i].r<<" ";
	}
	cout<<endl;
	//cout<<wei<<" ";*/
	zj=a[n].r/2;
	for(int i=1;i<=n;i++){
		if(a[i].l<=zj&&a[i].r>=zj){
			zi=i;
		}
	}
	int t=1,w=n;
	while(t<=zi&&w>=zi&&t!=w){
		if(a[t].x!=a[w].x){
			if(a[t].sum<a[w].sum){
				ans+=a[t].sum;
				a[w].sum-=a[t].sum;
				a[w].r-=a[t].sum;
				t++;
			}else if(a[t].sum>a[w].sum){
				ans+=a[w].sum;
				a[t].sum-=a[w].sum;
				a[t].l+=a[w].sum;
				w--;
			}else{
				ans+=a[t].sum;
				t++,w--;
			}
		}else{
			if(a[t].sum<a[w].sum){
				a[w].sum-=a[t].sum;
				t++;
			}else{
				a[t].sum-=a[w].sum;
				w--;
			}
		}
	}
	cout<<ans;
	
	return 0;
}
