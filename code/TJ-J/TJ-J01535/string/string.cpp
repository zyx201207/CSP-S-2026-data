#include<bits/stdc++.h>
using namespace std;
long long l,n,a[2000099][3],ch1,ans;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);	
	scanf("%d",&n);
	if(n==1){
		printf("%d",0);
		return 0;
	}
	for(int i=1;i<=n;i++){
	scanf("%c",&ch1);
		scanf("%lld%c%c",&a[i][1],&ch1,&a[i][2]);
	}
int t=1,w=n;
	for(;t!=w;){
		if(a[t][1]>a[w][1]){
			if(a[t][2]!=a[w][2]){
				ans+=a[w][1];
			}
			a[t][1]-=a[w][1];
			w--;
			continue;
		}
		if(a[t][1]==a[w][1]){
			if(a[t][2]!=a[w][2]){
				ans+=a[t][1];
			}
			if(t+1==w){
				break;
			}
			
			t++,w--;
			continue;
		}
		if(a[t][1]<a[w][1]){
			if(a[t][2]!=a[w][2]){
				ans+=a[t][1];
			}
			a[w][1]-=a[t][1];
			t++;
		}
	}
	printf("%lld",ans);

	
	return 0;
}
