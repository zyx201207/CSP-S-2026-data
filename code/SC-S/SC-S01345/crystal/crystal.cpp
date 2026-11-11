#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
int n,m,a[N],cnt[N],sum,mx=-1e9,q=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
			if(a[i]+j==a[i+1]+(m-j)){
				for(int k=1;k<=n;k++){
					if(a[i]+j==a[k] && a[i]+j==a[i+1]+(m-j)){
						sum++;
						q++;
					}
				}
				cnt[q]=sum+2;
			}
		}
		break;
	}
	if(n==1){
		cout<<1;
	}
	else{
		for(int i=1;i<=n;i++){
			mx=max(mx,cnt[i]);
		}
		cout<<mx;
	}
	return 0;
}