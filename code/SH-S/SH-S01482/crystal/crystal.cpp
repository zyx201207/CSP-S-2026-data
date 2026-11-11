#include<bits/stdc++.h>
using namespace std;
vector<int> a;
long long b;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,qk,tmp,jc=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		a.push_back(x);
		b+=x;
		if(jc<=2){
			tmp+=x;
			jc++;
		}
	}
	printf("%lld",abs(jc));
	return 0;
}
