#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int b[500005];
int c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		int cnt=1;
		for(int j=i;j<=n;j++){
			int f=1;
			for(int g=1;g<=cnt;g++){
				if(a[j]==b[g]){
					for(int h=g+1;h<=j;h++){
						b[h]=0;
						cnt--;
					}
					break;
				}
			}
			b[cnt]=a[j];
			cnt++;
		}
		for(int j=1;j<=cnt;j++){
			cout<<b[j]<<" ";
			c[b[j]]++;
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
//  (@_@)   (^_^)   (x_x)   ($_$)    :(      
//                                      
}

