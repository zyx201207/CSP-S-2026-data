#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
bool a[N][35],b[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,x;
	cin>>n>>m;
	m=n-m;
	for(int i=1;i<=n;i++){
		cin>>x;
		for(int j=0;j<=30;j++){
			if(x%2){
				a[i][j]=1;
			}x/=2;
		}
	}queue<int>q;
	int ans=0;
	for(int j=30;j>=0;j--){
		int zero=0,k=m;
		for(int i=1;i<=n;i++){
			if(b[i]){
				continue;
			}if(!a[i][j]){
				zero++;
				q.push(i);
			}
		}while(!q.empty()){
			int l=q.front();
			q.pop();
			if(zero<=k){
				m--;
				b[l]=1;
			}
		}if(zero<=k){
			ans+=1<<j;
		}
	}cout<<ans;
	return 0;
}
