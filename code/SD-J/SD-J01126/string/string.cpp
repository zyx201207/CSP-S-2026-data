#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N=200010;
int n,a[N];
LL cnt,ans;

struct AC{
	LL a;
	char c;
}e[N];
int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>e[i].a>>e[i].c;
	}
	for(int i=1,j=n;i<=j;){
		if(e[i].c!=e[j].c){
			ans+=min(e[i].a,e[j].a);
		}
		if(e[i].a>=e[j].a){
			e[i].a-=e[j].a;
			j--;
		}
		else{
			e[j].a-=e[i].a;
			i++;
		}
	}
	cout<<ans;
	return 0;
}

