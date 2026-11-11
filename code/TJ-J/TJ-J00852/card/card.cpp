#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,a[N],t[N];
int main(){
  	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x[N]={0},b[N]={0},cnt=1;
		for(int j=i;j<=n;j++){
			if(x[a[j]]==0||b[x[a[j]]+1]==0){
				x[a[j]]=cnt;
				b[cnt++]=a[j];
				b[cnt]=0;
			}else{
				cnt=x[a[j]];
				b[++cnt]=0; 
			}
		}
		cnt=1;
		while(b[cnt]!=0) {
//			cout<<b[cnt]<<" ";
			t[b[cnt++]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" "; 
	}
	fclose(stdin);
	fclose(stdout);
}
