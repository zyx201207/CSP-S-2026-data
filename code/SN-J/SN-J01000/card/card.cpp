#include<bits/stdc++.h>
using namespace std;
int a[200009],c[200009],d[2000009];
bool b[200009];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=0;
		d[i]=0;
	}
	for(int w=1;w<=m;w++){
		int k=1;
		for(int i=1;i<=n;i++){
			b[i]=0;
		}
		for(int i=1;i<=n;i++){
			if(b[a[i]]==0){
				b[a[i]]=1;
				c[k]=a[i];
				k++;
			}else{
				int ans;
				for(int j=1;j<=i;j++){
					if(a[j]==a[i]){
						ans=j;
						break;
					}
				}
				for(int j=ans;j<=n;j++){
					c[j]=0;
				}
				c[ans]=a[i];
				k=ans+1;
			}
		}
		for(int wk=1;wk<=k;wk++){
			for(int xy=1;xy<=m;xy++){
				if(c[wk]==xy){
					d[xy]++;
					break;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}

	return 0;
}
