//Trick||Treat!
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int num[200005],n,m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
    	scanf("%d",&num[i]);
	}
	sort(num+1,num+n+1,cmp);
	int ans=num[1];
	for(int i=2;i<=m;++i){
		ans&=num[i];
	}
	printf("%d",ans);
    return 0;
}
