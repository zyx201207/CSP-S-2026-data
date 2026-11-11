#include<bits/stdc++.h>
using namespace std;
long long tot,n,a[200001];
char c[200001];
struct ing{
	long long l,r;
	char dq;
}v[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int k=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		v[i].dq=c[i];
		v[i].l=k+1;
		v[i].r=k+a[i];
		k+=a[i];
	}
	int u=k;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int il=u-(v[i].r-v[i].l+1)+1,ir=u;
			if(v[j].r>=il&&v[j].r<=ir){
				if(v[j].dq!=v[i].dq){
					if(v[j].l<=il){
						tot+=v[j].r-il+1;
					}
					else{
						tot+=v[j].r-v[j].l+1;
					}
				}
			}
		}
			u=u-(v[i].r-v[i].l+1);
	}
	cout<<tot;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
