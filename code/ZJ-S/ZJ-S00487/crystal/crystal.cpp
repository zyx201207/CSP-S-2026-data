#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <ctime>
#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))
using namespace std;
const int Mxn=500100;
long long n,m;
long long a[Mxn];
long long ans,anc;
bool A=true,B=true;
long long fb;

void dfs(int d){
    if(d>m){
    	int t[300];
        for(int i=1;i<=250;i++)t[i]=0;
        for(int i=1;i<=n;i++)t[a[i]+30]++;
        for(int i=1;i<=200;i++)ans=Max(ans,t[i]);
	    return;
	}
	for(int i=1;i<=n;i++){
		a[i]++;
    	dfs(d+1);
    	a[i]--;
	}
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=i)A=false;
		if(i==2)fb=a[2]-a[1];
		if(i>2&&(a[i]-a[i-1])!=fb)B=false;
	}
	if(B){
		long long i=1;
		m/=fb;
		if(m>980000000700000000){
			m-=980000000700000000;
			ans+=1400000000;
			i+=1400000000;
			goto ret;
		}
		if(m>720000000600000000){
			m-=720000000600000000;
			ans+=1200000000;
			i+=1200000000;
			goto ret;
		}
		if(m>500000000500000000){
			m-=500000000500000000;
			ans+=1000000000;
			i+=1000000000;
			goto ret;
		}
		if(m>320000000400000000){
			m-=320000000400000000;
			ans+=800000000;
			i+=800000000;
			goto ret;
		}
        if(m>180000000300000000){
			m-=180000000300000000;
			ans+=600000000;
			i+=600000000;
			goto ret;
		}
		if(m>80000000200000000){
			m-=80000000200000000;
			ans+=400000000;
			i+=400000000;
			goto ret;
		}
		if(m>20000000100000000){
			m-=20000000100000000;
			ans+=200000000;
			i+=200000000;
			goto ret;
		}
ret:
		for(;;i++){
			if(m>=i){
				m-=i;
				ans++;
			}else{
				if(m<i){
					ans++;
					printf("%lld\n",ans);
//					printf("%lf",(double)clock()/CLOCKS_PER_SEC);
					return 0;
				}
			}
		}
	}
	if(n<=5&&m<=10){
		ans=0;
		dfs(1);
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//Oct31==Dec25?









//AB        30
//1 2       10






/*
	sort(a+1,a+n+1);
	if(n<=5&&m<=10){
		long long it=1,ih=1,k=a[1];
		for(int i=1;i<=n;i++){
			if(a[i]==k)continue;
			ih=i-1;//>k
			anc=ih-it+1;//=k的个数 
			long long t=a[it+1]-a[ih];//相邻的差
			if((anc*t)<=m){//可以操作 
				m-=(anc*t);//减少操作次数
				k=a[it+1];//更新k值
				continue; 
			}else{
				//不能操作
				long long ic=(m/t);//最多转变的次数
				
			}
		} 
    }
    */
