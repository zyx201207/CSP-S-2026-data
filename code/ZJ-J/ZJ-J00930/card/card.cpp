#include<bits/stdc++.h>
using namespace std;
int b[500005],la[300005],x[300005],cn[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
		cout<<1;
	if(n<=5000){
		for(int i=1;i<=n;i++){
		for(int j=1;j<=5005;j++) x[j]=la[j]=0;
		int cnt=0;
		for(int j=i;j<=n;j++){
			if(!la[b[j]]) x[++cnt]=b[j],la[b[j]]=cnt;
			else{
				for(int k=la[b[j]]+1;k<=cnt;k++) la[x[k]]=0;
				cnt=la[b[j]];
			}
		}
		for(int i=1;i<=cnt;i++){
			cn[x[i]]++;
		}
	    }
	}
	else{
	    for(int i=1;i<=n;i++) cn[b[i]]++;
	    cn[b[n]]=n;
	}
	for(int i=1;i<=m;i++) cout<<cn[i]<<" ";
	return 0;
}

