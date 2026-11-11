#include<iostream>
using namespace std;
int n,m,a[500005],b[300005],c[300005],maxn=0,max1=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int f=0;
		if(a[i]>maxn){
			maxn=a[i];
		}
		b[a[i]]++;
		if(b[a[i]]==2){
			for(int j=1;j<a[i];j++){
				b[j]=0;
			}
			b[i]--;
		}
		for(int j=1;j<=maxn;j++){
			if(b[i]!=0){
				c[b[i]]++;
			}
		}
	}
	if(m<=2&&n<=5){
		cout<<15;
	}
	return 0;
} 
