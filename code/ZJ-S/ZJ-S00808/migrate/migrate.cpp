#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=200005;
ll c,t,a[N],step[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		step[1]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					step[j]=step[i]+1;
				}else{
					i=j-2;
					break;
				}
			}
		}
		cout<<step[n]<<endl;
	}
	
}
