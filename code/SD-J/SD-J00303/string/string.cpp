#include<bits/stdc++.h>
#define int long long 
using namespace std;
long long n,r,sum,num=0,ln,rn,ans,l;
struct gcc{
	int cnt;
	char c;
}a[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].cnt>>a[i].c;
		sum+=a[i].cnt;
	}
	l=1,r=n,ln=a[1].cnt,rn=a[n].cnt;
	while(num*2<sum){
		if(a[l].c!=a[r].c){
			if(ln<=rn){
				num+=ln;
				rn-=ln;
				ans+=ln;
				l++;
				ln=a[l].cnt;
				
			}else{
				num+=rn;
				ln-=rn;
				ans+=rn;
				r--;
				rn=a[r].cnt;
			}
		}else{
			if(ln<=rn){
				num+=ln;
				rn-=ln;
				l++;
				ln=a[l].cnt;
				
			}else{
				num+=rn;
				ln-=rn;
				r--;
				rn=a[r].cnt;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
} 
