#include<bits/stdc++.h>
using namespace std;
int n,m,ma1,a[200000],ma2,t;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]>ma1){
			ma1=a[i];
		}else{
			if(ma2<a[i]){
				ma2=a[i];
			}
		}
	}
	cout<<ma1 and ma2; 
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
