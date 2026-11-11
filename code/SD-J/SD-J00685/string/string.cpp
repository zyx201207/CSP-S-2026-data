#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,a[N],ans;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		if(c[l]==c[r]){//两字符相等 
			if(a[l]>a[r]){//操作r 
				a[l]-=a[r--];
			}else{//操作l 
				a[r]-=a[l++];
			}
		}else{
			if(a[l]>a[r]){//操作r 
				a[l]-=a[r];
				ans+=a[r--];
			}else{//操作l 
				a[r]-=a[l];
				ans+=a[l++];
			}
		}
	}
	cout<<ans;
	return 0;
}

