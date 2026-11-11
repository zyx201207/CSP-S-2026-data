#include<bits/stdc++.h>
using namespace std;
int ab[1000010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.in","w",stdout);
	int n,m;
	string a,b;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int c;
		cin>>c;
		ab[i]=c;
	}
	int maxn=-99999;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int d=0;
			string z;
			int a1=ab[i],a2=ab[j];
			while(a1=0){
				int g=a1%2;
				a[d]=g;
				d++;
				a1/=2;
			}
			d=0;
			while(a2=0){
				int g=a2%2;
				b[d]=g;
				d++;
				a2/=2;
			}
			d=0;
			for(int ii=1;ii<=a.size();ii++){
				if(a[i]==1&&b[j]==1){
					z[d]=1;
					d++;
				}
			}
			int cc=0;
			for(int ij=0;ij<=d;ij++){
				if(z[ij]==1){
					cc+=pow(2,d);
				}
			}
			if(cc>maxn){
				maxn=cc;
			}
		}
	}
	cout<<maxn;
	return 0;
}
