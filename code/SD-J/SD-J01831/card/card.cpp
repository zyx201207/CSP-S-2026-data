#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define TIE ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int N=5e5+5,M=3e5+5;
int n,m;
int a[N];
int last[M];
bool ap[M];
int ans[M];
int cf[N];
int hy[N]; 

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	TIE;
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int k=1;k<=n;k++){
		//³õÊ¼»¯ 
		for(int i=0;i<=n;i++) cf[i]=hy[i]=0;
		for(int i=0;i<=m;i++) ap[i]=last[i]=0;
		
		for(int i=k;i<=n;i++){//ÌøÔ¾ 
			if(last[a[i]]==0) last[a[i]]=i;
			else{
				cf[last[a[i]]+1]+=1;
				cf[i+1]-=1;
			}
		}
		for(int i=k;i<=n;i++){
			hy[i]=hy[i-1]+cf[i];
			if(hy[i]==0||i==n){
				ap[a[i]]=1;
			}
		}
		for(int i=1;i<=m;i++){
			if(ap[i]) ans[i]++;
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
