#include<bits/stdc++.h>
using namespace std;
int n,m,c[35];
int a,aa[200005],len,x,tot;
bool mp[200005][35],ok[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		aa[i]=a;
		int l=1;
		while(a>0){
			if(a&1) c[l]++,mp[i][l]=1;
			a/=2;
			l++;
		}
		l--;
		len=max(len,l);
	}
	for(int i=len;i>=1;i--){
		if(c[i]>=m){
			for(int j=1;j<=n;j++){
				if(!mp[j][i]&&!ok[j]){
					for(int l=1;l<=len;l++){
						if(mp[j][l]) c[l]--;
					}
					ok[j]=1;
				}
			}
		}
	}
	int p=m;
	for(int i=1;i<=n;i++){
		if(p<=0) break;
		if(ok[i]) continue;
		else{
			if(p==m) tot=aa[i];
			else tot=(tot&aa[i]);
			p--;
		}
	}
	cout<<tot;
	return 0;
}