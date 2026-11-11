#include <bits/stdc++.h>

#define fr for
#define int long long

using namespace std;

inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0'||ch>'9'){
		f|=ch=='-';ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return f?-x:x;
}

const int N=5007;
int d[N][N],cnt[N][N];
int a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read();
	int T=read();
	while(T--){
		int n=read(),_d=read();
		fr(int i=1;i<=n;i++)a[i]=read();
		fr(int i=1;i<=n;i++){
			fr(int j=1;j<=n;j++){
				d[i][j]=0x3f3f3f3f3f3f3f3f;
				cnt[i][j]=0;
			}
		}
		fr(int i=1;i<=n;i++){
			fr(int j=1;j<=n;j++){
				if(abs(a[i]-a[j])<=_d)d[i][j]=1,cnt[i][j]=1;
			}
		}
		fr(int i=1;i<=n;i++){
			d[i][i]=0x3f3f3f3f;cnt[i][i]=1;
		}
		fr(int k=1;k<=n;k++){
			fr(int i=1;i<=n;i++){
				fr(int j=1;j<=n;j++){
					if(d[i][k]+d[k][j]<d[i][j]){  
						d[i][j]=d[i][k]+d[k][j];
						cnt[i][j]=cnt[i][k]*cnt[k][j];
					}
					else if(d[i][k]+d[k][j]==d[i][j]){
						cnt[i][j]+=cnt[i][k]*cnt[k][j];
					}
				}
			}
		}
		int ans=0;
		fr(int i=1;i<=n;i++){
			fr(int j=i+1;j<=n;j++){
//				cerr<<cnt[i][j]<<' '<<i<<' '<<j<<' '<<d[i][j]<<"!!!\n";
				ans+=(cnt[i][j]==2);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}/*
直接每个点跑一遍最短路计数 三次方，只有 24pts
n^2 怎么写
zrr help me

首先肯定都是直接飞，谁闲着没事绕一圈啊 

 zrr help me
 
然后呢 

zrr help me

这个长度最短怎么定义

zrr help me

哦看错提了

zrr help me

我去，zrr 1h AK 了！！！！！！！！！！！

zrr help me

 嗯方不会做是不是可以退役了
 
zrr help me

不急，现在 16:11，还有两个多小时

zrr help me

怎么刻画这个限制

zrr help me

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

设 f_{i,j} 为最短路，cnt_{i,j} 为计数

然后区间 dp 即可，等等这不是三次方的吗

思考到 16:55

zrr help me

算了先打暴力，复杂度三次方 

zrr help me 

 17:04 阳历过了，24pts
 
 zrr /bx/bx/bx 
 
 zrr 224pts 可以 7 吗
 
 不管了我去打 T4 15pts 了 
 
  17:41 我打完 T4 了
	
zrr 
*/
 
/*

ZRR carry me fly!!!!!!!!!!!!!

zrr so cute!!!!!!!!!!

zrr teach me T3 T4!!!!!!!!!!!!!!!!

##########  #########   #########
       ##   #				 #	#				 #
			##    #				 #	#				 #
		 ##			#        #	#				 #
		##			#########		#########
	 ##  			# ###				# ###
	##				#  ###			#  ###
 ##					#   ### 		#   ###
########## 	#    #####	#    #####

By C_0_a4S,Luogu_uid=1424067

都 2026 年了，我怎么还在考 CSP？
            ###################
         ############??############
       ##############??##############
      ################################
     #######????????????????????#######
    ####################################
    #############?????????##############
    #############?#######?##############
    #############?????????##############
    ####################################
     #######????????????????????#######
      ######?##################?######
       ############??????############ 
         ########?######?##?#######  
           #######?######????#### 
               ##############
 Oct31==Dec25?


*/

