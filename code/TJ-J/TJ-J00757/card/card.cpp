#include<bits/stdc++.h>
using namespace std;
int c[300005];
int a[500004];
int b[500004];
struct tong{
	int w;
	int pos;
}ton[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int t=1;
		for(int j=i+1;j<=n;j++){
			if(ton[a[j]].w==0){
				b[t]=a[j];
				ton[a[j]].w++;
				ton[a[j]].pos=t;
				t++;
			}else{
				for(int i=ton[a[j]].pos;i<t;i++){
					ton[a[i]].w=0;
				}
				t=ton[a[j]].pos;
				ton[a[j]].w++;
			}		
		}
		for(int i=0;i<=t;i++){
			if(ton[a[i]].w==1)c[a[i]]++;
		}
	}
	for(int i=0;i<m;i++){
		cout<<c[a[i]]<<' ';
	}
	return 0;
} 
