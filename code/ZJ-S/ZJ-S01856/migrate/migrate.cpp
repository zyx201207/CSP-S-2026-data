#include<bits/stdc++.h>
using namespace std;
int C,T,n,dp[2000005][2],s[2000005],dy[2000005];
long long d,x[2000005],ans;
pair<int,int> dp1[305][305];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&C,&T);
	if(C<=6){
		while(T--){
			ans=0;
			scanf("%d%lld",&n,&d);
			for(int i=1;i<=n;i++){
				scanf("%lld",&x[i]);
				dp1[i][i]={0,1};
				for(int j=1;j<i;j++){
					dp1[i][j]={0x3f3f3f3f,0};
				}
			}
			for(int i=2;i<=n;i++){
				for(int j=1;j<i;j++){
					for(int k=i-1;k>=j;k--){
						if(x[i]-x[k]>d){
							break;
						}
						if(1+dp1[k][j].first<dp1[i][j].first){
							dp1[i][j]={dp1[k][j].first+1,dp1[k][j].second};
						}else if(1+dp1[k][j].first==dp1[i][j].first){
							dp1[i][j].second+=dp1[k][j].second;
						}
					}
					if(dp1[i][j].second==2){
						ans++;
					}
				}
			}
			printf("%d\n",ans);
		}
	}else{
		while(T--){
			ans=0;
			scanf("%d%lld",&n,&d);
			for(int i=1;i<=n;i++){
				scanf("%lld",&x[i]);
				dp[i][0]=dp[i][1]=0;
				s[i]=0;
			}
			int o1=0,p1=0,o2=0,p2=0,o3=0,p3=0,o4=1;
			long long s1=0,s2=0,s3=0;
			for(int i=1;i<=n;i++){
				while(o4<i&&x[i]-x[o4]>d){
					s[dy[o4]]--;
					if(o1>=dy[o4]){
						p1--;
					}
					if(o2>=dy[o4]){
						p2--;
					}
					if(o3>=dy[o4]){
						p3--;
					}
					o4++;
				}
				while(o3<o4&&p3<=2){
					s2+=dp[o3][0];
					o3++;
					p3+=s[o3];
				}
				while(o2<o3&&p2<=1){
					s2-=dp[o2][0];
					s1+=dp[o2][1];
					s3+=dp[o2][0];
					o2++;
					p2+=s[o2];
				}
				while(o1<o2&&p1<=0){
					s1-=dp[o1][1];
					s3-=dp[o1][0];
					o1++;
					p1+=s[o1];
				}
				dp[i][0]=s3+i-o4+1;
				dp[i][1]=s1+s2;
				ans+=dp[i][1];
				s[o4]+=1;
				if(o1==o4){
					p1++;
				}
				if(o2==o4){
					p2++;
				}
				if(o3==o4){
					p3++;
				}
				dy[i]=o4;
			}
			printf("%lld\n",ans);
		}
	}	
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
8 3
0 1 2 4 8 10 11 13

0 1
10 3
0 3 6 7 8 9 10 11 14 17

0 1
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983
*/
