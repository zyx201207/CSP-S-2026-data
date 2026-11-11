#include<cstdio> 
#include<algorithm>
int get(long long x){
	int res=0;
	while(x){
		x-=(x&-x);
		res++;
	}return res;
}

const int MAXN=2e5+5,MAXM=2e5+5-1;
const int MAXLOGA=35;
struct NUMBER{
	int x,s1=0;
	bool bin[MAXLOGA];
}a[MAXN];
void build(int i){
	int t=a[i].x;
	for(int j=0;j<=30;j++){
		if((1<<j)&t) a[i].bin[j]=1;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].x);
		a[i].s1=get(a[i].x);
	}
	for(int i=1;i<=n;i++) build(i);
	std::sort(a+1,a+n+1,[](const NUMBER &a,const NUMBER &b){
		return a.x>b.x;
	});
	/*
	for(int i=1;i<=n;i++){
		printf("i=%d ",a[i].x);
		for(int j=30;j>=0;j--) printf("%d",a[i].bin[j]);puts("");
	}
	*/
	int c=m;
	int ans=0;
	for(int s=30;s>=0;s--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i].bin[s]) cnt++;
		}
		if(cnt>=m){
			for(int i=1;i<=n;i++){
				if(a[i].bin[s]&&c) {c--;
					if(!ans) ans=a[i].x;
					else ans&=a[i].x;
				}
			}
			break;
		}
	}
	printf("%d\n",ans);
//	printf("%d\n",get(2147483648));
	return 0;
}
