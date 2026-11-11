#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int s[N],a[N],maxn=-1,n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		int x=s[i]%10,y=s[i+1]%10;
		if(x>y){
			maxn=s[i];
		}else if(x<y){
			maxn=s[i+1];
		}
	}
	cout<<maxn;
	return 0;
}