//T3 - migrate
#include<cstdio>
const int N = 2e6 + 5;
const long long INF = 1e16;
int c,T,n;
long long d,pos[N],ans;
//long long prv[N],nxt[N];
long long brute_dp[5005],brute_sum[5005];
inline void brute();
inline void special_A();
inline void gogogo();
inline long long fread();
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	if(c==0 || (c>=11 && c<=12)){
		special_A();
		return 0;
	}
	if(c<=10){
		brute();
		return 0;
	}
//	gogogo();
	fclose(stdin);fclose(stdout);
	return 0;
}
inline long long fread(){
	long long c,x=0,f=1;
	c=getchar();
	while(c!=45 && (c<48 || c>57)){
		c=getchar();
	}
	if(c==45){
		f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=x*10+c-48;
		c=getchar();
	}
	return x*f;
}
inline void special_A(){
	while(T--){
		ans=0;
		scanf("%d",&n);
		d=fread();
//		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			pos[i]=fread();
//			scanf("%lld",&pos[i]);
		}
		if(n<=2){
			printf("0\n");
			continue;
		}
		long long delt=pos[2]-pos[1];
		if(delt>=d){
			printf("0\n");
			continue;
		}
		long long tttt=d/delt;
		if(tttt==1){
			printf("0\n");
			continue;
		}
		ans=n-2*tttt+1;
		if(ans<0)ans=0;
		printf("%lld\n",ans);
	}
}
//inline void gogogo(){
//	while(T--){
//		ans=0;
//		scanf("%d%lld",&n,&d);
//		for(int i=1;i<=n;i++){
//			scanf("%lld",&pos[i]);
//		}
//		if(n<=2){
//			printf("0\n");
//			continue;
//		}
//		prv[1]=1;//left
//		for(int i=2;i<=n;i++){
//			if(pos[i]-pos[i-1]>d){
//				prv[i]=1;
//			}
//			else{
//				if(prv[i-1]<=2){
//					prv[i]=prv[i-1]+1;
//				}
//				else{
//					if(pos[i]-pos[i-2]<=d && pos[i-1]-pos[i-3]<=d){
//						prv[i]=3;
//					}
//					else{
//						prv[i]=prv[i-1]+1;
//					}
//				}
//			}
//		}
//		nxt[n]=1;//right
//		for(int i=n-1;i>=1;i--){
//			if(pos[i+1]-pos[i]>d){
//				nxt[i]=1;
//			}
//			else{
//				if(nxt[i+1]<=2){
//					nxt[i]=nxt[i+1]+1;
//				}
//				else{
//					if(pos[i+2]-pos[i]<=d && pos[i+3]-pos[i+1]<=d){
//						nxt[i]=3;
//					}
//					else{
//						nxt[i]=nxt[i+1]+1;
//					}
//				}
//			}
//		}
//		for(int i=1;i<=n-3;i++){
//			if(pos[i+2]-pos[i]<=d && pos[i+3]-pos[i+1]<=d && pos[i+3]-pos[i]>d){
//				if(i==1 || pos[i+1]-pos[i-1]<=d){//u=i
//					if(i+3==n || pos[i+4]-pos[i+2]<=d){//v=i+3
//						ans++;
//					}
//					else{//v>=i+3
//						ans+=nxt[i+3];
//					}
//				}
//				else{//u<=i
//					if(i+3==n || pos[i+4]-pos[i+2]<=d){//v=i+3
//						ans+=prv[i];
//					}
//					else{//v>=i+3
//						ans+=prv[i]*nxt[i+3];
//					}
//				}
//			}
//		}
//		printf("%lld\n",ans);
//	}
//}
inline void brute(){
	while(T--){
		ans=0;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&pos[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				brute_dp[j]=INF;
				brute_sum[j]=0;
			}
			brute_dp[i]=0;brute_sum[i]=1;
			int lst=i;
			for(int j=i+1;j<=n;j++){
				while(lst<=j && pos[j]-pos[lst]>d){
					lst++;
				}
				if(lst==j)break;
				brute_dp[j]=brute_dp[lst]+1;
				brute_sum[j]=brute_sum[lst];
				int now=lst+1;
				while(now<=j && brute_sum[j]<=2 && brute_dp[now]==brute_dp[lst]){
					brute_sum[j]+=brute_sum[now];
					now++;
				}
				if(brute_sum[j]==2){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
}
