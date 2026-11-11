#include <iostream>
#include <cstdio>
using namespace std;
const int N=2e5+7;
const int M=6e8+7;
int n,x,l=1,r,mid,num[N];
long long ans;
char ch[M],y;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		getchar();
		scanf("%lld %c",&x,&y);
		num[i]=num[i-1]+x;
		for(int j=num[i-1]+1;j<=num[i];j++){ch[i]=y;}
	}
	for(r=num[n],mid=(r+1)/2;l<=mid;){
		if(ch[l++]!=ch[r--])ans++;
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

