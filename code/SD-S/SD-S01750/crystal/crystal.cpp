#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n;long long a,al,ans,d,k=1,m;bool f=1;
int main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=0;i<n;i++){
		al=a;
		scanf("%d",&a);
		if(i!=0&&al!=a)f=0;
	}
	if(f){//sp A
		ans=floor((sqrt(8*m+1)-1)/2);
		printf("%lld",min(ans,(long long)n));
	}else{//sp B
		d=abs(a-al);
		while(1){
			if(k<=n&&m-d*k>=0)m-=d*k,ans++,k++;
			else break;
		}
		printf("%lld",ans);
	}
	return 0;
}

