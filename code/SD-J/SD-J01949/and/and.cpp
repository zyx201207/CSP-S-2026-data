#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
bool b[N][35],ans[35];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m,o=0;
	cin>>n>>m;
	int a[n+5],len=0,len_=0,x=1,t[m+5],j=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int top=0;
		while(a[i]!=0){
			b[i][++top]=a[i]%2;
			a[i]/=2;
		}
		len=max(len,top);
	}
	int f=0;
	while(f!=m){
		for(int i=1;i<=n;i++){
			if(b[i][len]){
				f++;
				t[++j]=i;
			}
		}
		if(f==m){
			if(x)
			len_=len;
			break;
		}else if(f>m){
			len--;
			if(x) len_=len;
			x=0;
			j=0;
			f=0;
		}
	}
	for(int i=1;i<=len_;i++){
		ans[i]=1;
	}
	for(int i=1;i<=m;i++){
		for(int k=1;k<=len_;k++){
			if(b[t[i]][k]==0){
				ans[i]=0;
			}
		}
	}
	for(int i=len_;i>=1;i--){
		if(ans[i]==1){
			int q=1;
			for(int k=i;k>=1;k--) q*=2;
			o+=q;
		}
	}
	cout<<o;
	return 0;
}
