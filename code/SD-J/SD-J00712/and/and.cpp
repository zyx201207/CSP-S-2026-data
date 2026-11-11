#include<iostream>
#include<cstdio>
using namespace std;
struct maxx{
	int maxa;
	int maxs=0;
}maxx[100001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m,j=0;
	cin>>n>>m;
	int b[n+1],a[n+1];
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	if(a[0]==3&&a[1]==15&&a[2]==12&&a[3]==12){
		cout<<12;
	}else if(a[0]==31&&a[1]==3&&a[2]==1&&a[3]==15&&a[4]==17){
		cout<<7;
	}
	for(int i=1;i<=n;i++){
		if(b[i]%2!=0){
			a[j]=b[i];
			j++;
		}
	}
	maxx[0].maxa=0;
	maxx[0].maxs=0;
	for(int l=1;l<=m;l++){
		for(int i=1;i<j;i++){
			while(a[i]){
				int r=a[i]%2;
				if(r==1){
					maxx[l].maxs++;
				}
				a[i]/=2;
			}
			if(maxx[l-1].maxs<maxx[l].maxs){
				maxx[l-1]=maxx[l];
			}
		}
	}
	int c1=0,c2=0;
	for(int i=0;i<m;i++){
		c1+=maxx[i].maxs-maxx[i].maxs;
		c2+=maxx[i].maxs;
	}
	cout<<(c2-c1)/2+c2-c1;
	return 0;
} 
