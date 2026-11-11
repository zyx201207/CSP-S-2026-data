#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e6+5;
const int mod=1e9+7;
int n,m,cnt;
int a[N];
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		int q=i;
		bool f=false;
		for(int j=q;j<=n;j++){
			if(a[j]==i)f=true;
		}if(f==false){
			a[++n]=a[i];
			cnt++;
		}else {
			for(int j=q;j<=n;j++){
				a[j]==0;
			}
			a[++n]=a[i];
		}
	}cout<<cnt;
	return 0;
}

