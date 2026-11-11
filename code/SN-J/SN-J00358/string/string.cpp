#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200010];
char c[200010];
int sum;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i],sum+=a[i];
	sum/=2;
	int l=1,r=n,cnt=0,suml=0,sumr=0;
	int kl=a[l],kr=a[r];
	char cl=c[l],cr=c[r];
	while(l<=r){
		if(cl==cr){
			if(kl==kr){
				suml+=kl,sumr+=kr;
				l++,r--;
				kl=a[l],kr=a[r];
				cl=c[l],cr=c[r];
			}else if(kl>kr){
				suml+=kr,sumr+=kr;
				r--;
				kl-=kr,kr=a[r];
				cr=c[r];
			}else{
				suml+=kl,sumr+=kl;
				l++;
				kr-=kl,kl=a[l];
				cl=c[l];
			}
		}else{
			if(kl==kr){
				suml+=kl,sumr+=kr;
				l++,r--;
				cnt+=kl;
				kl=a[l],kr=a[r];
				cl=c[l],cr=c[r];
			}
			else if(kl>kr){
				suml+=kr,sumr+=kr;
				r--;
				cnt+=kr;
				kl-=kr,kr=a[r];
				cr=c[r];
			}else{
				suml+=kl,sumr+=kl;
				l++;
				cnt+=kl;
				kr-=kl,kl=a[l];
				cl=c[l];
			}
		}
		if(suml>=sum||sumr>=sum)break;
	}
	cout<<cnt;
}
//gugugaga gugugaga gugugaga!!!
