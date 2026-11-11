#include<iostream>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[n+1],b[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int s[m+1];
	for(int i=1;i<=m;i++){
		s[i]=0;
		b[i]=i;
	}
	for(int z=0;z<=m;z++){
		for(int i=1;i<=n;i++){
			for(int q=1;q<=n;q++){
				if(a[i]==a[q]){
					for(int w=i;w<=q-i;w++){
						a[w]=a[w+q-i];
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int q=1;q<=n;q++){
				if(a[i]==b[q]){
					s[q]++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
