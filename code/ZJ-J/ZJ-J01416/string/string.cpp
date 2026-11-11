#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],b[N]={0};
long long l,sum=0;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		b[i]=b[i-1]+a[i];
	}long long p=1,q=b[n];
	while(p<q){
		char x,y;
		for(int i=1;i<=n;i++){
			if(p>b[i-1]&&p<=b[i]){x=c[i];break;}
		}for(int i=1;i<=n;i++){
			if(q>b[i-1]&&q<=b[i]){y=c[i];break;}
		}if(x!=y)sum++;
		p++;
		q--;
	}cout<<sum;
	return 0;
}
