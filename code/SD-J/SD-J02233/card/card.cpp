#include<iostream>
#include<cstring>
using namespace std;
#define ll long long
const int N=5e5+10;
int n,m,a[N],b[N];
ll t[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int k=1;k<=n;k++){
		memset(t,0,sizeof(t));
		memset(b,0,sizeof(b));
		int b_l=0;
		for(int i=k;i<=n;i++){
			if(!t[a[i]]){
				t[a[i]]++;
				b[++b_l]=a[i];
			}else{
				for(int j=1;j<=b_l;j++){
					if(b[j]==a[i]){
						b_l=j;
						break;
					}
				}
			}
		}
		for(int i=1;i<=b_l;i++){
			ans[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
