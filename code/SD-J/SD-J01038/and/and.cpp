#include<bits/stdc++.h>
using namespace std;
int a[1000000];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1,cmp);
	if(m==1 and n<=2000)cout<<a[1];
	else if(n<=2000 and m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(ans<(a[i]&a[j]))ans=(a[i]&a[j]);
			}
		}cout<<ans<<'\n';
	}else if(n<=2000 and m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}cout<<ans<<'\n';
	}else if(m==n-1){
		int ANS=a[2];
		for(int i=3;i<=n;i++){
			ANS&=a[i];
		}for(int i=2;i<=n;i++){
			int ans=a[1];
			for(int j=2;j<=n;j++){
				if(j!=i)ans&=a[j];
			}if(ans>ANS)ANS=ans;
		}cout<<ANS<<'\n';
	}else{
		cout<<a[m];
	}
} 
