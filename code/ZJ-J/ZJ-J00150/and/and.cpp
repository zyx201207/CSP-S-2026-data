#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
ll a[200005];
ll pow_of_2[200005];
int ha[200005];
int dha[2000005][35];
bool de[200005];
void init(){
	pow_of_2[0]=1;
	for(int i=1;i<=30;i++)pow_of_2[i]=pow_of_2[i-1]*2;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;//49152 262142
	init();
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		int len=0;
		while(pow_of_2[len]<x)len++;
		for(int k=len;k>=0;k--){
			if(x>=pow_of_2[k])ha[k]++,dha[i][k]++,x-=pow_of_2[k];
		}
	}
//	for(int i=0;i<=30;i++)cout<<ha[i]<<' ';
//	cout<<"\n";
//	for(int j=1;j<=n;j++){
//		for(int i=0;i<=30;i++)cout<<dha[j][i]<<' ';
//		cout<<endl;
//	}
	ll ans=0,cnt=n;
	for(int k=20;k>=0;k--){
		if(ha[k]>=m){
//			cout<<ha[k]<<' ';
			for(int i=1;i<=n;i++){
				if(dha[i][k]==0 && de[i]==0){
					de[i]=1;
					for(int j=0;j<=20;j++)ha[j]-=dha[i][j];
				}
			}
//			for(int i=0;i<=30;i++)cout<<ha[i]<<' ';
//			cout<<"\n";
//			cout<<ha[k]<<endl;
			ans+=pow_of_2[k];
		}
	}
	cout<<ans;
	return 0;
}
//Trick||Treat!
