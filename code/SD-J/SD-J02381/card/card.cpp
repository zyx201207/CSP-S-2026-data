#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int a[N],b[N];
int main(){
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	int n,m;
	bool l=1;
	scanf("%d %d",&n,&m);
	scanf("%d",&a[0]);
	b[a[0]]++;
	for(int i=1;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]<a[i-1]) l=0;
		b[a[i]]++;
	}
	if(l){
		for(int i=0;i<n;i++){
			b[a[i]]=i+1;
		}
		for(int i=0;i<m-1;i++){
			printf("%d ",b[i+1]);
		}
		printf("%d",b[m]);
	}
	else{
		b[a[n-1]]=n;
		for(int i=0;i<m-1;i++){
			printf("%d ",b[i+1]);
		}
		printf("%d",b[m]);
	}
	
	return 0;
} 
