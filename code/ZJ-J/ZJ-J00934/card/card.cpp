#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[7],z[3];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;

	for(int i=0;i<n;i++){
		cin>>a[i];
		z[a[i]]++;
	}
	if(m==2){
		cout<<z[1]<<" "<<z[2];
	}else{
		cout<<z[1];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}