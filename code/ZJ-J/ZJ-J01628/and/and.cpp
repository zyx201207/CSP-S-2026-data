#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e5+10;
int a[N],ans;
bool d[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if((!d[j])&&((a[j]>>i)&1)){
				cnt++;
				if(cnt>=m){
					break;
				}
			}
		}
		if(cnt>=m){
			for(int j=1;j<=n;j++){
				if(d[j])continue;
				if(!((a[j]>>i)&1)){
					d[j]=1;
				}
			}
			ans=ans*2+1;
		}
		else{
			ans=ans*2;
		}
	}
	cout<<ans;
	return 0;
}
