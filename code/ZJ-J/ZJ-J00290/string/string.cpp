#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct p{
	char ch;
	long long num;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a[i].num,&a[i].ch);
	}
	int l=1,r=n;
	long long leftch=a[1].num,rightch=a[n].num;
	while(l<r){
		if(a[l].ch!=a[r].ch){
			ans+=min(leftch,rightch);
		}
		long long minch=min(leftch,rightch);
		leftch-=minch;
		rightch-=minch;
		if(leftch==0){
			l++;
			leftch=a[l].num;
		}
		if(rightch==0){
			r--;
			rightch=a[r].num;
		}
	}
	printf("%lld",ans);
	return 0;
}
