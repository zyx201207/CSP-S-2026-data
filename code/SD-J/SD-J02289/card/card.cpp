#include<bits/stdc++.h>
using namespace std;
long long a[500005],c[300005],l[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n;
	long long m;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0+i;j<n;j++){
			int s=a[j];
			for(int x=0;x<j;x++){
				if(l[x]==s){
					for(int y=x;y<j;y++){
						l[y]=0;
					}
				}
			}
			l[j]=s;
		}
		for(int x=0+i;x<n;x++){
			c[l[x]]++;
		}
		for(int y=0;y<=500005;y++){
			l[y]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
}
