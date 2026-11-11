#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,p;
long long t_ch[500005],l[500005];
struct asd{
	long long zh,ti;
}x[300][500005];
struct asd{
	long long f,to;
}jh[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&p);
    for(int i=0;i<m;i++){
		scanf("%lld",&t_ch[i]);
	}
	for(int i=0;i<n;i++){
		long long k;
		scanf("%lld",&k);
		l[i]=k;
		for(int j=0;j<k;j++){
			scanf("%lld%lld",&x[i][j].zh,&x[i][j].ti);
		}
	}for(int i=0;i<p;i++){
		scanf("%lld%lld",&jh[i].f,&jh[i].to);
		for(int j=0;j<n;j++){
			for(int k=0;k<l[j];k++){
				for(int h=j;h<n;h++){
					for(int g=0;g<l[k];g++){
						if(x[j][k].zh==x[h][g].zh){
							ans=t_ch[jh[i].f]+
						}
					}
				}
			}
		}
	}
    return 0;
}
//ni hao zhei ti ye tai nan le ba geng ben bu huei zuo 
//liu xin chen yu 2026 10 31 xie xia 
//wo bu zhi dao wo ru hei jing ru csp-s de wo dou shi xia xie de wo zheng shi fu lei
