#include<bits/stdc++.h>
using namespace std;
int nxt[500005],num[300005],st[500005],ans[500005];
int n,m;
int a[500005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(n<=5000&&m<=3000) {
		for(int i=1; i<=n; i++) {
			memset(num,0,sizeof(num));
			int tp=i-1;
			for(int j=i; j<=n; j++) {
				if(!num[a[j]]) {
					st[++tp]=a[j];
					num[a[j]]=tp;
				} else {
					while(tp!=num[a[j]]) {
						num[st[tp]]=0;
						tp--;
					}
//					num[a[j]];
					//num[i]=tp;
				}
			}
			for(int j=i; j<=tp; j++) {
				//		cout<<st[j]<<" ";
				ans[st[j]]++;
			}//cout<<endl;
		}
		for(int i=1; i<=m; i++) {
			cout<<ans[i]<<" ";
		}
	}
	for(int i=1;i<=n;i++){
		num[a[i]]++;
		if(a[i-1]==a[i]){
			ans[a[i]]++;
		}else{
			if(num[a[i]]&1)ans[a[i]]+=(i);	
		}
	}
	for(int i=1;i<=m;i++){
//		cout<<ans[i]<<" ";
//		ans[i]+=ans[i-1];
		cout<<ans[i]<<" ";
	}
}

