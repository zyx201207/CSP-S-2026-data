#include<cstdio>
#include<cstring>
using namespace std;
bool done[5005][5005],ans[5005][5005];
long long pos[5005],no,t,n,d;
bool check(int fir,int dest){
	done[fir][dest]=1;
	if(fir+1==dest || fir==dest){
		ans[fir][dest]=0;
		return 0;
	}
	if(fir+2==dest && pos[dest]-pos[fir]<=d){
		ans[fir][dest]=1; 
		return 1;
	}
	for(int i=fir;i<dest-1;i++){
		if(pos[i+1]-pos[i]>d){
			ans[fir][dest]=0;
			return 0;
		}
	}
	if(done[fir][dest])	return ans[fir][dest];
	bool lstate=done[fir][fir+dest<<1]?ans[fir][fir+dest<<1]:check(fir,fir+dest<<1);
	bool rstate=done[(fir+dest<<1)+1][dest]?ans[(fir+dest<<1)+1][dest]:check((fir+dest<<1)+1,dest);
	if(lstate && rstate)	return 0;
	if((!lstate)&&(!rstate))	return 0;
	return 1;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d",&no);
	scanf("%d",&t);
	while(t--){
		int yes=0;
		memset(done,0,sizeof(done));
		memset(ans,0,sizeof(ans));
		scanf("%d",&n,&d);
		for(int i=1;i<=n;i++)	scanf("%d",&pos[i]);
		if(no>=11 && no<=14){
			if(pos[3]-pos[1]<=d){
				printf("%d\n",n-2);
			}
			else printf("%d\n",0);
			continue;
		}
		for(int i=1;i<=n-2;i++){
			for(int j=i+2;j<=n;j++){
				if(check(i,j))	yes++;
			}
		}
		printf("%d\n",yes);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
