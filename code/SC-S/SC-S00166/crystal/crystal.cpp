#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=5e5+5;
int a[maxn],f[maxn];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=0;
	sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) f[i]=a[i]-a[i-1];
    if(n<=5000){
    	for(int i=1;i<=n;i++){
    		int sum=0;
    		for(int j=i;j<=n;j++){
    			sum+=f[j]*(j-i+1);
    			if(sum>m){
    				ans=max(ans,j-i+1);
    				break;
				}
			}
		}
		return cout<<ans,0;
	}
	int sum=0;
    for(int i=1;i<=n;i++){
	    sum+=f[i]*i;
	    if(sum>m) return cout<<i,0;
	}
	return 0;
}
/*
Phigros 文盲记不住版 


                        ======  ||            ======= 
                       ||   ||  ||        *  ||    || ** ""___  *=====*   *=====
                        =====   ||=====  ==  ||====||  ||"     ||    ||   ||
                       ||       ||   ||   |        ||  ||      ||    ||   ||===*
                       ||       ||   ||   |        ||  ||      ||    ||       ||
                                        """"  """"""            *=====*   ====
                                    点·击·屏·幕·继·续 
									        4.0.1 
									        
									        
									        
									        
									        
									        
									        
									        
					       	  （那个主页的纹路太难画了，没画呀）
								
								
								
								
+ Phigros
    + 课题模式
	+ 全部曲目
+单曲精选
+过去的章节
+第五章 那字叫啥虹灯牌  PLAY<-
+第六章 方舟蜃景   PLAY
+第七章 时钟链接   PLAY
+第八章 是啥来着我忘了  BOOT
+第九章 是啥来着又忘了	BOOT				 
+支线一 忘忧宫  PLAY
+支线二 那两个字叫什么日  PLAY
+支线三 线索已缺失  PLAY						 
+支线四 线索已缺失  PLAY							 						 



									        
name                      EZ  HD  IN  AT
NYA!!(Phigros ver.)       2   8   13  \
前面忘了中间忘了什么VIP   3   9   13  \
cryout                    3   9   13  \
Reimei                    6   11  15  \
尊师后面忘了              6   11  15  \
Spas中间忘了odic          8   12  15  16   <-
Behind 后面忘了           3   9   12  \



 

            Spas中间忘了odic AT16 

Tips:我超，劲爆                 等待的英文是什么我不知道... 
 
 
 
 
 
 
 
 
 
 
                中间的谱记不到 
                
                
                
                
                
                
                

	饿，要结束了，还没有结算，算了，明年在更     
	   希望能收录进2026 CSP SC迷惑行为大赏             
*/