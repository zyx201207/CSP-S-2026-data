#include<bits\stdc++.h>
using namespace std;
long long n,m;
int a[500005];
struct no{
	int t=0,an=0;
}b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >>n>>m;
	bool bk=1;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		b[a[i]].t++;
		if(a[i]<a[i-1])bk=0;
	}
	if(bk==1){
		long long q=0;
		for(int i=1;i<=m;i++){
			q+=b[i].t;
			if(b[i].t!=0)cout<<q<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		int q[300005]={};
		for(int j=i;j<=n;j++){
			q[j]=a[j];
			for(int k=j-1;k>=i;k--){
				if(q[k]==q[j]){
					for(int w=k;w<j;w++){
						q[w]=-1;
					}
					break;
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(q[j]>0){
				b[q[j]].an++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(b[i].t!=0)cout<<b[i].an<<" ";
	}
	return 0;
}
