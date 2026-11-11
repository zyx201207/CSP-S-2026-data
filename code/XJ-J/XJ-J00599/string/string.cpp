#include<bits/stdc++.h>
#define int long long
using namespace std;
//气死我了，这题真难
const int N=2e5+5;
int n,a,ans,flag;
string s;
string f;
signed main(){
	//fast in
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	//in
	cin>>n;
	for(int i=1,j=1;i<=n;i++){
		cin>>a>>s;
		for(int j=1;j<=a;j++){
			f+=s;
		}
	}

	//work
	int mid=f.size()/2;

	if(f.size()%2==0){
		for(int l=0,r=f.size()-1;l<=mid,r>mid;l++,r--){
			if(f[l]!=f[r]){
				ans++;
			}
		}
	}

	if(f.size()%2==1){
		for(int l=0,r=f.size()-1;l<mid,r>mid;l++,r--){
			if(f[l]!=f[r]){
				ans++;
			}
		}
	}

	//debug
	//cout<<f<<endl;

	//out
	cout<<ans;

	return 0;
}
//da da da da da, wo3 yao4 wan2 yuan2 shen2
//气死我了做这个破题用了一个半小时