//胡海瑧 西安市铁一中学 SN-J00626 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=5e5+5;
const int M=3e5+5;
int a[N],b[M];
int ans[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=5&&m<=2){
		if(m==1){cout<<n;return 0;}
		else{
//			sort(a+1,a+n+1);
			int l1,l2;
			b[1]=a[1];
			for(int i=2;i<=n;i++){
				if(a[i]!=b[1]){b[2]=a[i];break;}
			}
			for(int i=n;i>=1;i--){
				if(a[i]==b[1]){l1=i;break;}
			}
			for(int i=n;i>=1;i--){
				if(a[i]==b[2]){l2=i;break;}
			}
			cout<<l1<<" "<<l2;return 0;
		}
	}
	else{
		for(int i=1;i<=n;i++) b[i]=a[i];
		int tot=0;
		for(int i=1;i<=n;i++){
			int c=upper_bound(a+1,a+n+1,a[i])-a;
			if(a[i]!=a[i+1]) ans[++tot]=c-1;
		}
		for(int i=1;i<=tot;i++) cout<<ans[i]<<" ";
	}
	return 0;
}
