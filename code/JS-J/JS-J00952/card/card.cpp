#include<bits/stdc++.h>
using namespace std;
int b[3000005];
int find(int a,int h){
	for(int i=1;i<=a;i++){
		if(b[i]==h) return i;
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,t=0;
	cin>>n>>m;
	int a[300005],c[300005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=n;j++){
			if(!find(t,a[j])){
				b[++t]=a[j];
			}else{
				for(int q=find(t,a[j]);q<=t;q++){
					b[q]=0;
				}
				t=find(t,a[j]);
			}
		}
		for(int j=1;j<=t;j++){
			if(b[t]<=m){
				c[b[t]]++;
			}
	    } 
	}
		    
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
