#include<bits/stdc++.h>
using namespace std;
long long a[5000005];
long long t[5000005];
long long y[5000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		y[a[i]]++;
	}
	int f,c;
	c=0;f=0;
	for(int i=1;i<=n;i++){
		f=0;c=0;
		for(int j=i;j<=n;j++){
			if(a[j]==a[i]){
				c++;
				f++;
				if(f==2){
					f=0;
				}
			}
			if(f==0){
				t[a[j]]++;
//				cout<<t[a[j]]<<endl;
			}
			if(y[a[i]]%2==1&&y[a[i]]==c){
				t[a[j]]++;
//				cout<<t[a[j]]<<endl;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
//		cout<<y[i]<<" ";
	}
	return 0;
}
