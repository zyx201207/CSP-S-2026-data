#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
const int M=1e5+10;
int a[N];
bool b[M];
int ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(m==1) cout<<n;
	else{
		int anss=0;
		for(int i=1;i<=n;i++){
			anss++;
			if(a[i]!=a[i+1]) cout<<anss<<" ";
		}
	}
	return 0;
}
