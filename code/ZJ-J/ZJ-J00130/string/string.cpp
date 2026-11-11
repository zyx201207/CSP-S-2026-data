#include<bits/stdc++.h>
using namespace std;

int n,a[200001],maxa;
char c[200001];
char zao[201001];//1-12,17-18,
int lzao,ans;//1-12

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		maxa=max(maxa,a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++)
			zao[++lzao]=c[i];
	}		
	for(int i=1;i<=lzao;i++){
		if(zao[i]!=zao[lzao+1-i]){
			ans++;
			zao[i]=zao[lzao+1-i];
		}	
	}
	cout<<ans;
}