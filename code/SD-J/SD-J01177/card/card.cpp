#include<bits/stdc++.h>
using namespace std;
int a[200010],b[200010];
int ton[5001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int x=1;x<=n;x++){
		int q=1;
		for(int y=x-1;y<=n;y++){
			b[q]=a[y];
			q++;
		}
    for(int i=1;i<=q;i++){
    	for(int j=q;j>=i+1;j--){
    		if(b[i]==b[j]){
    			for(int k=j;k<=n;k++){
    				ton[b[k]]++;
				}
				for(int z=1;z<=n;z++){
					ton[b[z]]++;
				}
			}
		}
	}
}
    for(int i=1;i<=3000;i++){
    	if(ton[i]!=0){
    		cout<<ton[i]<<' ';
		}
	}
	return 0;
} 
