#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int n,m,a[N],a2[N];
int d1[N],d2[N];
void indelete(int s,int f){
	for(int t=s-1;t>=1;t--){
		if(a[t]==f) {
			a[t]=0;
			break;
		}
		a[t]=0;
		d1[a[t]]--;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a2[i];
	if(m==1) {
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(d1,0,sizeof(m+3));
		for(int j=i;j<=n;j++) a[i]=a2[i];
		for(int j=i;j<=n;j++){
			if(d1[a[j]]>0){
				indelete(j,a[j]);
			} 
			if(d1[a[j]]==0) d1[a[j]]++;
		}
		for(int j=1;j<=m;j++){
			if(d1[j]!=0) d2[j]+=1; 
		}
	}
	for(int j=1;j<=m;j++){
		cout<<d2[j]<<" ";
	}
	cout<<endl;
	return 0;
} 
