#include<bits/stdc++.h>
using namespace std;
struct stu{
	int a;
	char c;
}a[200005];
int n;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i].a,&a[i].c);
	}
	int i=1,j=n;
	while(i<j){
		int mi=min(a[i].a,a[j].a);
		if(a[i].c!=a[j].c){
			ans+=mi;
		}
		a[i].a-=mi;a[j].a-=mi;
		if(a[i].a==0)i++;
		if(a[j].a==0)j--;
	}
	printf("%lld",ans);
	return 0;
}

