#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5000005],b[5000005],c[5000005],k=1,t=0,f=0,z=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	t=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=a[i];
	}
	while(t--){
		for(int i=k;i<=n;i++){
			for(int j=k;j<=n;j++){
				if(a[i]==c[j]){
				    for(int q=j+1;q<=n;q++){
						c[q]=0;
				    }
				    f=1;
			    }else if(c[j]==0&&c[j-1]!=0&&f==0){
				    c[j]=a[i];
				    f=1;
			    }
			    if(f==1){
			    	break;
				}
			}
			f=0;
		} 
		k++;
		for(int i=z;i<=n;i++){
			b[c[i]]++;
		}
		for(int i=k;i<=n;i++){
			c[i]=a[i];
		}
		z++;
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 
