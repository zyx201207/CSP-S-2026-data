#include<bits/stdc++.h>
using namespace std;
long long a[500005]={};
long long b[500005]={};
int jishu[300005]={};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int q=1;
		for(int j=i;j<=n;j++){
			b[q]=a[j];
			q++;
		}
		for(int i=1;i<=q-1;i++){
			
		}
	}
	
	

	return 0;
} 
