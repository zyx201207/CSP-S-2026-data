#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int b[10000000];
int main(){
	freopen("card.in","r",stdin);
	freoprn("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n],c[n];
	bool p[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
		    c[j]=a[j];
		    p[i]=true;
		}
		for(int j=i;j<n;j++){
			for(int z=j+1;z<n;z++){
				if(c[j]==c[z]&&p[i]){
					for(int k=j;k<z;k++){
						p[i]=false;
					}
				}
			}
		}
		for(int j=i;j<n;j++){
			if(p[j]){
				int l=c[j];
			    b[l-1]++;
			}
		}
	}
	for(int i=0;i<m;i++){
		cout<<b[i]<<" ";
	}
	fclose(stdin);
	flcose(stdout);
	return 0;
}