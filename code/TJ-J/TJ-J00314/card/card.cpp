#include <bits/stdc++.h>
using namespace std;

#define LL unsigned long long

LL n,m;
LL a[500005],b[500005],c[500005],d[500005];

int main(){

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(LL i = 1;i <= n;i++) cin>>a[i];
	for(LL i = 1;i <= n;i++){
		for(LL j = i;j <= n;j++) c[j] = a[j];
		for(LL j = 1;j <= m;j++) b[j] = 0;
		for(LL j = i;j <= n;j++){
			if(b[c[j]] != 0){
				for(LL g = b[c[j]];g < j;g++){
					c[g] = 0;
				}
				b[c[j]] = j;
			}
			else{
				b[c[j]] = j;
			}
		}
		for(LL j = i;j <= n;j++)
			if(c[j] != 0)
				d[c[j]]++;
	}
	for(LL i = 1;i <= m;i++) cout<<d[i]<<" ";
    
    return 0;
}


















/*
note
luogu_name: ___HAAVK___
The sky belongs to HAAVK!!!
            ， 
            ，， 
            ，，， 
        ，  ，，，  ， 
      ，，  ，，，  ，， 
    ，，，  ，，，  ，，， 
  ，，，，  ，，，  ，，，， 
，，，，，  ，，，  ，，，，， 
  ，，，，  ，，，  ，，，， 
    ，，，  ，，  ，，，， 
	  ，，  ，  ，  ，， 
	    ，，  ，，  ， 
		    ，，， 
		      ，  
		      
	        HAAVK 
bilibiliname: wang/ pai/ fei- xing/ yuan/007
/\
|
luogu si- xin\ wo\/ xie\ xie\ , zhi- chi/ hu\ guan- 
wo\/ shi/ zai\ shi\ li\ jie/ le\
xi- wang\ ni\/ gu\/ neng/ shou- lu\
T1 T2 yi\/ jing- xie\/ hao\/ le-
T3 T4 bao\ li\ mo/ ni\/ xie\/ de- zi\ ji\/ dou- bu/ ren\ shi- TAT time:2026/10/31 11:15:05  Number36 in No.3, TianJinUniversity 
*/ 
