#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],cur=30;//cur为开始的最高位 
int cnt[35]={},ans=0;//cnt记录每一位1的个数，ans为最终答案 
bool flag[N]={};//flag为真时代表已经被删去了 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		for(int k=0;k<=30;k++){
			if(a[i]<(1<<k))
				break;
			if(a[i]&(1<<k))
				cnt[k]++; 
		}
	}
	while(!cnt[cur])
		cur--;
	for(;cur>=0;cur--){
		if(cnt[cur]<m){
			continue;
		}
		ans+=(1<<cur);
		for(int i=1;i<=n;i++){
			if(flag[i])
				continue;
			if(!(a[i]&(1<<cur))){
				flag[i]=true;
				for(int k=0;k<cur;k++){
					if(a[i]<(1<<k))
						break;
					if(a[i]&(1<<k))
						cnt[k]--; 
				}
			}
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
