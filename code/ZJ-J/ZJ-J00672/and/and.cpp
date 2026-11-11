#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
bool b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=30;i>=0;i--){
		int N=1<<i,num=0;
		for(int i=1;i<=n;i++){
			if(!b[i]&&(a[i]&N)==N){
				num++;
			}
		}
		if(num>=m){
			ans+=N;
			for(int i=1;i<=n;i++){
				if((a[i]&N)==0)b[i]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}