#include<cstdio>
#include<algorithm>
#include<cassert>
#include<string>
int n;
const int maxn=2e5+5;
struct item{
	int cnt,type;
	item(){}
	item(int cnt,char type):cnt(cnt),type(type-'a'){}
}a[maxn];
int main(){
	//freopen("test2.in","r",stdin);
	//freopen("t.out","w",stdout);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int cnt;char tmp[5];
		scanf("%d%s",&cnt,&tmp[1]);
		assert('a'<=tmp[1]&&tmp[1]<='z');
		a[i]=item(cnt,tmp[1]);
	}
	long long ans=0;
	for(int i=1,j=n;i<j;){
		ans+=a[i].type==a[j].type?0:std::min(a[i].cnt,a[j].cnt);
		if(a[i].cnt>a[j].cnt) a[i].cnt-=a[j--].cnt;
		else if(a[i].cnt==a[j].cnt) i++,j--;
		else a[j].cnt-=a[i++].cnt;
	}
	printf("%lld\n",ans);
	return 0;
}
