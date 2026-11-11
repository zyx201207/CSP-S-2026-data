#include<bits/stdc++.h>
using namespace std;
#define N 500005
struct q{
	int shu,xia;
}a[300005];
int n,m;
int b[N],c[N],d[300005];
long long num,cnt;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out ","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		c[i]=b[i];
	}
	int cnt=1;
	for(int k=1;k<=n;k++){
		for(int i=cnt;i<=n;i++){
			int l,k;
			a[b[i]].shu++;
			if(a[b[i]].shu==2){
				for(int j=a[b[i]].xia;j<i;j++){
					if(b[j]!=0){
						a[b[j]].shu--;
					}
					b[j]=0;
				}
			}
			a[b[i]].xia=i;
		}
		for(int i=cnt;i<=n;i++){
			if(b[i]!=0){
				d[b[i]]++;
			}
		}
		for(int i=1;i<=n;i++){
			b[i]=c[i];
		}
		cnt++;
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
} 
