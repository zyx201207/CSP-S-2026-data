#include<bits/stdc++.h>
using namespace std;
    long long n,m,a[500005],cnt,nxt,f[500005],num[500005],w[500005],q;
int main(){

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    bool flag=1;
    for(int i=1;i<=n;i++){
    	scanf("%lld%lld",&a[i]);
    	if(a[i]<a[i-1]){
    		flag=0;
		}
	}
	if(flag==1){
		for(int i=1;i<=n;i++){
			w[a[i]]++;
		}
		num[0]=0;
		for(int i=1;i<=m;i++){
			num[i]=num[i-1];
			while(w[i]>0){
				num[i]++;
				w[i]--;
			}
		}
		for(int i=1;i<=m;i++){
			printf("%lld",&num[i]);
		}
	}
	for(int i=1;i<=n;i++){
		cnt=0;
		for(int now=i;now<=n;now++){
			flag=1;
			q=cnt;cnt=0;
			for(int k=1;k<=q;k++){
				if(a[now]==a[k]){
					flag=0;
					nxt=k;
				}
				if(flag==0){
					f[k]=0;
				}
				else{
					cnt++;
				}
			}
			if(flag==0){
				f[nxt]=a[now];
				cnt++;
			}
			else{
			    cnt++;
				f[cnt]=a[now];
			}
		}
		for(int now=1;now<=cnt;now++){
			num[f[now]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<" ";
	}
}
