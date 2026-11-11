#include <bits/stdc++.h>
using namespace std;

#define LL unsigned long long

LL n,m,sum = 0;
long long f[500005];
bool flag = false;
struct x{
	long long a;
	//long long d,sum;
}y[500005];

bool cmp(x b,x c){
	return b.a < c.a;
}
/*
bool cmpb(x b,x c){
	return b.sum < c.sum;
} 
*/
bool cmpc(long long b,long long c){
	return b < c;
}

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(LL i = 1;i <= n;i++){
		cin>>y[i].a;
		if(i >= 3)
			if(y[i].a - y[i - 1].a != y[i - 1].a - y[i - 2].a){
				flag = true;
			}
	}
	sort(y + 1,y + n + 1,cmp);
	/*
	for(LL i = 1;i <= n;i++){
		y[i].d = y[i].a - y[i - 1].a + y[i - 1].d;
	}
	for(LL i = 1;i <= n;i++){
		for(LL j = 1;j < i;j++){
			y[i].sum = y[i].sum - y[j].d + y[i].d;
		}
	}
	sort(y + 1,y + n + 1,cmpb);
	*/
	long long maxn = -2e9;
	for(LL i = 1;i <= n;i++){
		long long sum = 0,count = 0,sum1 = m;
		for(LL j = 1;j <= n;j++){
			f[j] = -2e9;
			if(i == j || y[j].a > y[i].a) continue;
			f[j] = y[i].a - y[j].a;
			//count++;
		}
		sort(f + 1,f + n + 1,cmpc);
		for(LL j = 1;j <= n;j++){
			if(sum1 - f[j] < 0) break;
			else if(f[j] != -2e9){
				sum1 -= f[j];
				sum++;
			}
		}
		maxn = max(maxn,sum);
	}
	if(flag == true) cout<<maxn + 1;
	else cout<<maxn;
	return 0;
}/*
note
2026/10/31 17:56:40 CSP-S NO.17 in class302,TianjinUniversity,TianJin,China
luogu name:___HAAVK___
gang- cai/ hua\ zi\ fu/ hua\ bei\ jian- kao\/ lao\/ shi- wei/ guan- le\
*/



































/*

                          ¨~
                          ¨~¨~
                          ¨~¨~¨~
                      ¨~  ¨~¨~¨~  ¨~
                    ¨~¨~  ¨~¨~¨~  ¨~¨~
                  ¨~¨~¨~  ¨~¨~¨~  ¨~¨~¨~
                ¨~¨~¨~¨~  ¨~¨~¨~  ¨~¨~¨~¨~
              ¨~¨~¨~¨~¨~  ¨~¨~¨~  ¨~¨~¨~¨~¨~
                ¨~¨~¨~¨~  ¨~¨~¨~  ¨~¨~¨~¨~
                  ¨~¨~¨~  ¨~¨~¨~¨~¨~¨~¨~
                    ¨~¨~¨~¨~¨~¨~  ¨~¨~
                      ¨~  ¨~¨~¨~  ¨~
                          ¨~¨~¨~
                            ¨~     
							
							         
¨~      ¨~      ¨~          ¨~      ¨~      ¨~  ¨~    ¨~
¨~      ¨~     ¨~¨~        ¨~¨~      ¨~    ¨~   ¨~  ¨~
¨~¨~¨~¨~¨~    ¨~  ¨~      ¨~  ¨~      ¨~  ¨~    ¨~¨~
¨~      ¨~   ¨~    ¨~    ¨~    ¨~      ¨~¨~     ¨~  ¨~
¨~      ¨~  ¨~¨~¨~  ¨~  ¨~¨~¨~  ¨~      ¨~      ¨~    ¨~

                       ¨~
                      ¨~¨~
                     ¨~¨~
                    ¨~¨~      ¨~
                   ¨~¨~      ¨~¨~
                  ¨~¨~     ¨~ ¨~¨~
                 ¨~¨~   ¨~  ¨~ ¨~¨~
                ¨~¨~    ¨~¨~    ¨~¨~
               ¨~¨~     ¨~¨~¨~   ¨~¨~
              ¨~¨~¨~¨~¨~¨~¨~¨~¨~¨~¨~¨~
             ¨~¨~¨~¨~¨~¨~¨~¨~¨~¨~¨~¨~¨~

¨~¨~¨~¨~    ¨~¨~¨~¨~¨~  ¨~          ¨~¨~¨~¨~¨~      ¨~
¨~      ¨~  ¨~          ¨~              ¨~         ¨~¨~
¨~      ¨~  ¨~¨~¨~      ¨~              ¨~        ¨~  ¨~
¨~      ¨~  ¨~          ¨~              ¨~       ¨~    ¨~
¨~¨~¨~¨~    ¨~¨~¨~¨~¨~  ¨~¨~¨~¨~¨~      ¨~      ¨~¨~¨~  ¨~

¨~¨~¨~¨~¨~    ¨~¨~¨~    ¨~¨~¨~¨~      ¨~¨~¨~    ¨~¨~¨~¨~¨~
¨~          ¨~      ¨~  ¨~      ¨~  ¨~      ¨~  ¨~
¨~¨~¨~      ¨~      ¨~  ¨~¨~¨~¨~    ¨~          ¨~¨~¨~
¨~          ¨~      ¨~  ¨~     ¨~   ¨~      ¨~  ¨~
¨~            ¨~¨~¨~    ¨~      ¨~    ¨~¨~¨~    ¨~¨~¨~¨~¨~


luogu Name:___HAAVK___
*/ 
