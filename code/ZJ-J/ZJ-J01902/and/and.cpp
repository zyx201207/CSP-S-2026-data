#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int n,m;
long long o[200001];
long long ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>o[i];
	}
	if (m==1){
		for (int i=1;i<=n;i++){
			ans=max(ans,o[i]);
		}
		cout<<ans;
	}else if (m==2){
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				long long sum=0;
				int p=o[i],q=o[j];
				string a,b,c;
				int la,lb,lc;
				while (p!=1&&p!=0){
					if (p%2==0){
						a=a+"0";
					}else{
						a=a+"1";
					}
					p/=2;
				}
				if (p==1){
					a=a+"1";
				}else{
					a=a+"0";
				}
				while (q!=1&&q!=0){
					if (q%2==0){
						b=b+"0";
					}else{
						b=b+"1";
					}
					q/=2;
				}
				if (q==1){
					b=b+"1";
				}else{
					b=b+"0";
				}
				la=a.size(),lb=b.size();
				for (int i=0;i<min(la,lb);i++){
					if (a[i]=='1'&&b[i]=='1'){
						c=c+"1";
					}else{
						c=c+"0";
					}
				}
				lc=c.size();
				for (int i=0;i<lc;i++){
					if (c[i]=='1'){
						sum=sum+pow(2,i);
					}
				}
				ans=max(ans,sum);
			}
		}
		cout<<ans;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}