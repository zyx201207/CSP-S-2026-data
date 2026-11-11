#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=1e6+10;
int a[N],s[N],v[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m; cin>>n>>m;
	int A=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) A=0;
	}
	if(A){
		for(int i=1;i<=n;i++){
			s[a[i]]=i;
//			cout<<a[i]<<" "<<i<<endl;
//			cout<<i<<" ";
		}
		for(int i=1;i<=m;i++) cout<<s[i]<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(v,0,sizeof v);
		for(int j=i;j<=n;j++){
			if(v[a[j]]==0){
				v[a[j]]=j;
			}
			else{
				for(int k=v[a[j]];k<j;k++){
					v[a[k]]=0;
				}
				v[a[j]]=j;
			}
		}
//		cout<<i<<"dao n:"<<endl;
		for(int i=1;i<=m;i++){
//			cout<<v[i]<<" ";
			if(v[i]) s[i]++;
		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++) cout<<s[i]<<" ";
//	for(int i=n;i>=1;i--){
//		if(v[a[i]]==0){
//			v[a[i]]=1;
//			s[a[i]]=max(i,s[a[i]]);
//		}else{
//			for(int j=i+1;j<=n;j++){
//				if(a[j]==a[i]) break;
//				s[a[j]]--;
//			}
//		}
//	}
//	for(int i=1;i<=m;i++){
//		cout<<s[i]<<" ";
//	}
	return 0;
}