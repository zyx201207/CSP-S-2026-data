#include<bits/stdc++.h>
#include<string>
using namespace std;
const int N=2e5+7;
int n;
struct node{
	long long l;
	char c;
}a[N];
void solve(){
	int i=1,j=n;
	long long ans=0;
	int i_l=a[i].l;
	int j_l=a[j].l;
	while(i<j){
		if(a[i].c!=a[j].c){
			ans+=min(i_l,j_l);
		}
		if(i_l>j_l){
			i_l-=j_l;
			j_l=a[--j].l;
		}else if(i_l<j_l){
			j_l-=i_l;
			i_l=a[++i].l;
		}else{
			i_l=a[++i].l;
			j_l=a[--j].l;
		}
	}cout<<ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long maxn=-1e9;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].c;
		maxn=max(maxn,a[i].l);
	}solve();
	return 0;
}
