#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005;
int n,lt,rt,haf=0,bak=0,l=0,ans=0;
int a[N];
char c[N];
bool vis=true;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	lt=1;
	rt=n;
	while(lt<rt&&lt<(n+1)/2&&rt>(n+1)/2){
		if(a[lt]!=a[rt]||c[lt]!=c[rt]){
			if(a[lt]>a[rt]){
				rt--;
				a[lt]-=a[rt];
				ans+=a[rt];
			}
			else{
				lt++;
				a[rt]-=a[lt];
				ans+=a[lt];
			}
		}
		else{
			lt++;
			rt--;
		}
	}
	cout<<ans<<endl;
	return 0;
}

