#include<bits/stdc++.h>
using namespace std;
constexpr int N=2e5+10;
int n,m,a[N],S,all;
bool check(int T){
	all=0;
	for(int i=0;i<n;i++)all+=((a[i]&T)==T);
	return all>=m;
}
int main(){
	freopen("and.in","r",stdin),freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i= 0;i< n;i++)scanf("%d",&a[i]);
	for(int i=30;i>=0;i--){
		if(check(S|(1<<i)))S|=(1<<i);
	}
	printf("%d",S);
	return 0;
}
//大家好,我有志于进入迷惑行为大赏。
