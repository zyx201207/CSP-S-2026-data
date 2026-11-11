#include<bits/stdc++.h>
using namespace std;
long long a[1000000],cnt[1000000];
struct {
	bool isused;
	int c;
}b[1000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int t=1;
	while(t<=n){
		for(int i=t;i<=n;i++){
			if(b[a[i]].isused){
				for(int j=b[a[i]].c;j<=i;j++){
					b[a[j]].isused=false;
				}
			}
			b[a[i]].isused=true,b[a[i]].c=i;
		}
		for(int i=1;i<=300000;i++){
			if(b[i].isused){
				cnt[i]++;
			}
			b[i].isused=false,b[i].c=0;
		}
		t++;
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" "; 
	}
	return 0;
}
