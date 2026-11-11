#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
long long rin(){
	long long ans = 0;
	int opt=  1;
	char t = getchar();
	while((t<'0'||t>'9')&&(t!='-'))t=getchar();
	if(t=='-'){
		opt=-1;t=getchar();
	}
	while(t>='0'&&t<='9'){
		ans = ans*10+t-'0';t=getchar();
	}
	return ans*opt;
}
void rout(long long d){
	if(d/10)rout(d/10);
	putchar('0'+d%10);
}
//int hd[N],tl[N];//if i is the head or the tail
int x[N];
int cf[5005],stp[5005];
int R[5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,_;c=rin();_=rin();
	while(_--){
		int n,d;n=rin();d=rin();
		for(int i = 1;i<=n;i++)x[i]=rin();
		if(1<=c&&c<=10){
			int l = 1;
			for(int i = 1;i<=n;i++){
				while(i>=l&&x[i]-x[l]>d){
					R[l++] = i-1;
//					cout<<R[l-1]<<" ";
				}
			}
			while(l<=n)R[l++] = n;
			long long ans = 0;
			for(int i = 1;i<=n;i++){//i is start
				cf[i+1] = 1;
				cf[R[i]+1] = -1;
				int sum = 0,lst = i;//lst is go ? step can go to the farthest
				for(int j = i+1;j<=n;j++){
					if(lst<j)lst = R[lst];
					if(lst<j)break;
					sum+=cf[j];
//					cout<<j<<" "<<sum<<"\n";
					if(sum==2)ans++;
//					cout<<sum<<" ";?
//					cout<<lst<<" "<<R[j]<<"  ";
					if(R[j]>=lst+1){
						cf[lst+1]+=sum;cf[R[j]+1]-=sum;
					}
				}
				for(int j = i;j<=n+1;j++)cf[j] = 0;
//				cout<<ans<<" ";
			}
			rout(ans);putchar('\n');
		}
		else{
			if(c==11||c==12){
				if(d<x[2]-x[1]||n<=3){
					rout(0);putchar('\n');
				}
				else{
					if(2*d<x[3]-x[1]){
						rout(0);putchar('\n');
					}
					else{
						rout(n-3);putchar('\n');
					}
				}
			}
		}
	}
	return 0;
}

