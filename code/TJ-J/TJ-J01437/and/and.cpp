#include<bits/stdc++.h>
using namespace std;
long long a[200005],num,b[200005],n,m,sum;
void dfs(long long cnt,long long num){
	if(cnt>=m){
		sum=max(sum,num);
		cout<<endl;
		return ;
	}
	cnt++;
	for(int i=cnt;i<=n;i++){
		if(cnt==1) num=a[i];
		else num&=a[i];
		
		cout<<num<<"->";
		dfs(cnt,num);
	}
}
int main(){
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
    sum=a[n-m+1];
    for(int i=n-m+2;i<=n;i++) sum&=a[i];
    //dfs(0,0);
	printf("%lld",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
