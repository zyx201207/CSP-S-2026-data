#include<bits/stdc++.h>
using namespace std;
long n,m,a[100001];
int er[101]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32668,65336};
bool flagg[1000001],fl[1000001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int num=0,t=15;
	while(num!=m&&t>=0){
		num=0;
		for(int i=1;i<=n;i++)
			flagg[i]=0;
		for(int i=1;i<=n;i++){
			if(fl[i]!=1 && a[i]&er[t]==er[t]){
				num++;
				flagg[i]=true;
				
			}
		}
		if(num>=m){
			for(int i=1;i<=n;i++)
				if(flagg[i]==0)
					fl[i]=true;
		}
		t-=1;
	}
	int ort;
	for(int i=1;i<=n;i++)
		if(fl[i]==0){
			ort=a[i];
			break;
		}
	for(int i=1;i<=n;i++)
		if(fl[i]==0)
			ort=ort&a[i];
	cout<<ort;
	return 0;
}
