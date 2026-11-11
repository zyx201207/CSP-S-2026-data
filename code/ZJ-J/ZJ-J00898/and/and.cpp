#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=200005;
int n,m,a[maxn],b[maxn][45],anf,k,ans,c[maxn];
vector<int>A;vector<int>B;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;A.push_back(0);
	for(int i=1;i<=n;i++){cin>>a[i];A.push_back(i);c[i]=a[i];}
	for(int i=30;i>=0;i--){
		anf=(1<<i);
		for(int j=1;j<=n;j++){
			if(c[j]>=anf){c[j]=c[j]-anf;b[j][i]=1;}
		}
	}for(int i=30;i>=0;i--){k=0;
		if((A.size()-1)==m){break;}
		for(int j=1;j<=(int)(A.size()-1);j++){if(b[A[j]][i]==1){k++;B.push_back(A[j]);}}
		if(k>=m){
			A.clear();A.push_back(0);
			for(int j=0;j<(int)(B.size());j++){A.push_back(B[j]);}
		}B.clear();
	}ans=a[A[1]];
	for(int i=2;i<=(int)(A.size()-1);i++){ans=(ans&a[A[i]]);}
	cout<<ans;
	return 0;
}
