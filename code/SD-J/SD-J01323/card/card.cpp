#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m;
int a[N],b[N],t[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n>500){
		for(int i=n;i>=1;i--){
			if(t[a[i]]){
				for(int j=1;j<=m;j++){
					if(t[j]<t[a[i]]&&t[j]>i) t[j]=0; 
				}
			}else t[a[i]]=i;
			for(int j=1;j<=m;j++){
				if(t[j]) b[j]++;
			}
		}	
	}else{
		for(int T=1;T<=n;T++){
			memset(t,0,sizeof(t));
			for(int i=T;i<=n;i++){
				if(t[a[i]]){
					for(int j=1;j<=m;j++){
						if(t[j]>t[a[i]]) t[j]=0; 
					}
				}
				t[a[i]]=i;
			}
			for(int i=1;i<=m;i++){
				if(t[i]) b[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	return 0;
}
