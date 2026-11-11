#include<bits/stdc++.h>
using namespace std;
long long sum=0,n,m,b[200200],a[200200][35],c[200200],cb[200200],ans[35],x,cl,ma=-1,maa=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x);
		long long w=0;
		while(x!=0){
			w++;
			a[i][w]=x%2;
			x/=2;
			//cout<<w<<endl;
		}
		a[i][0]=w;
		ma=max(ma,w);
		c[i]=i;
	} 
	cl=n;
//	for(int i=1;i<=cl;i++){
//			cout<<c[i]<<' ';
//		}
//		cout<<endl;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=a[i][0];j++){
//			cout<<a[i][j];
//		}
//		cout<<endl;
//	} 
	for(long long k=ma;k>=1;k--){
		long long cp=0;
		for(int i=1;i<=cl;i++){
			if(a[c[i]][k]==1){
				cp++;
				cb[cp]=c[i];
			}
		}
		if(cp>=m){
			ans[k]=1;
			maa=max(maa,k);
			for(int i=1;i<=cp;i++){
				c[i]=cb[i];
			}
			cl=cp;
		}else{
			ans[k]=0;
		}
//		cout<<k<<' '<<cp<<' '<<cl<<':'<<endl;
//		for(int i=1;i<=cl;i++){
//			cout<<c[i]<<' ';
//		}
//		cout<<endl;
	}
	long long p=1;
	for(int i=1;i<=maa;i++){
		if(ans[i]==1) sum+=p;
		p*=2;
		//cout<<ans[i]<<' ';
	}
	printf("%lld",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
