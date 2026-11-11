#include<bits/stdc++.h>
using namespace std;
const int N=500100;
const int M=300100;
int n,m,maxn;
int a[N];
int s[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxn=max(maxn,a[i]);
	}
	for(int i=1;i<=n;i++){
		int index=0;
		int lin[n-i+1]={0};
		int t[maxn+1]={0};
		for(int j=i;j<=n;j++){
			if(!t[a[j]]){
				index++;
				lin[index]==a[j];
				t[a[j]]++;
			}else{
				int ai=index;
				while(a[ai]!=a[j]){
					index--;
					ai--;
					t[a[ai]]=0;
				}
			}
		}
		for(int j=1;j<=index;j++){
			s[lin[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
