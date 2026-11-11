#include<iostream>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,l,r,a,b,sum;
	long long x[250000];
	std::cin>>c>>t;
	for(int i=1;i<=t;i++){
		sum=0;
		std::cin>>n>>d;
		for(int j=1;j<=n;j++){
			std::cin>>x[j];
		}for(int j=1;j<=n;j++){
			a=0;
			b=0;
			l=j;
			r=l+1;
			while(x[r]-x[l]<=d && r<=n){
				r+=1;
			}if(r>n){
				r=n;
			}if(x[r]-x[l]>d){
				b+=1;
			}while(x[r]-x[l+1]<=d && b!=0 && x[r]!=x[l+1]){
				l+=1;
				a+=1;
			}if(a==2){
				sum+=1;
			}
		}std::cout<<sum<<endl;
	}return 0;
}
