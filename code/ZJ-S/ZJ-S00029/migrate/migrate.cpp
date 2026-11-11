#include<bits/stdc++.h>
using namespace std;
long long rd(){
	int m=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=!f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		m=m*10+ch-'0';
		ch=getchar();
	}
	return m*f;
}
void wr(long long num){
	if(num==0){
		return ;
	}
	if(num<0){
		putchar('-');
		num=(-num);
	}
	wr(num/10);
	putchar(num%10+'0');
}
long long c,t,n,d,a[20000005];
int main(void){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	c=rd(),t=rd();
	while(t--){
		n=rd();
		d=rd();
		long long ans=0,best=-9999999;
		for(long long i=1;i<=n;i++){
			a[i]=rd();
			if(a[i]>best) best=a[i];
		}
		sort(a+1,a+n+1);
		if(a[3]-a[1]>d){
			ans=1;
		}
		if(n<3){
			ans=0;
		}
		for(long long i=1;i<=n;i++){
			long long goal1=a[i]+d,goal2=a[i]+2*d;
			int i1=0,i2=0;
			if(goal1>=best){
				break;
			}
			for(int j=i;j<=n;j++){
				if(a[j]>goal1){
					break;
				}
				i1=j;
			}
			for(int j=i;j<=n;j++){
				if(a[j]>goal2){
					break;
				}
				i2=j;
			}
			ans+=i2-i1-1;
		}
		if(ans==0){
			putchar('0');
			putchar('\n');
			continue;
		}
		wr(ans+1);
		putchar('\n');
	}
	return 0;
}
