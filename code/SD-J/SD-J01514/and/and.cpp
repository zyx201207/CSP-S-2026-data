#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],t[35][200005],k[35],mx,sum,q,e[35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(int j=0;j<=30;j++){
			t[i][j]=0;
		}
	}
	for(long long i=1;i<=n;i++){
		long long mmm=0,ooo=a[i];
		while(ooo>0){
			if(ooo%2==1) t[mmm][++k[mmm]]=i;
			ooo/=2,mmm++;
		}
		mx=max(mx,mmm);
	}
	for(long long i=mx;i>=0;i--){
		if(k[i]>=m){
			long long h=0;
			for(long long l=1;l<=k[i];l++){
				bool ui=1;
				for(long long j=1;j<=q;j++){ 
					bool f=0;
					for(int g=1;g<=k[e[j]];g++){ 
						if(t[e[j]][g]==t[i][l]){
							f=1;
							break;
						}
					}
					if(f==0) ui=0; 
				}
				if(ui==1){
					h++; 
				}
			}
			if(h>=m){
				sum+=pow(2,i);
				e[++q]=i;
			}
		}
	}
	cout<<sum;
	return 0;
}
