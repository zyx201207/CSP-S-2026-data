#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;//n局数&&牌数 m牌种 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n;
	int a[n+1],ans[m+1],b[n+1];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	while(x<=n){
		for(int i=x;i<n;i++){
			for(int j=x;j<i;j++){
				if(b[j]==a[i]){
					y=1;
				}
				if(y=1){
					b[j]=-1;
				}
			}
			b[i]=a[i];
			y=0;
			
		}
		x++;
		for(int i=x;i<n;i++){
			if(b[i]!=-1){
				ans[b[i]]++;
			}
		}
	}
	cout<<1<<endl;
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	fclose(sdin);
	fcluse(stdout);
	return 0;
}
