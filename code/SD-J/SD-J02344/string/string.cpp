#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
struct node{
	int x;
	char c;
}k[N];
int n,ans,t;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int xx;
		char cc;
		cin>>xx>>cc;
		if(cc==k[t].c&&t!=0) k[t].x+=xx;
		else k[++t].x=xx,k[t].c=cc;
	}
	n=t,t=0;
	int i=1,j=n;
	while(i<=j){
		if(k[i].c==k[j].c){
			if(k[i].x==k[j].x){
				i++,j--;
				continue;
			}
			if(k[i].x<k[j].x){
				k[j].x-=k[i].x;
				i++;
			}else{
				k[i].x-=k[j].x;
				j--;
			}
		}else{
			if(k[i].x==k[j].x){
				ans+=k[i].x;
				i++,j--;
				continue;
			}
			if(k[i].x<k[j].x){
				ans+=k[i].x,k[j].x-=k[i].x;
				i++;
			}else{
				ans+=k[j].x,k[i].x-=k[j].x;
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}
