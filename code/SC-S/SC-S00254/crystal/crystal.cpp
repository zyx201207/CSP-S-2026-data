#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crytal.out","w",stdout);
	int n=1,m=0,a[1];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(1+a,1+a+n);
	int x=1,y=0,z=0,w=0;
	for(int y=1;y<=n;y++){
		if(y!=1){
			w+=(a[y]-a[y-1])*(y-1);
		}while(m<w)
			w-=a[y]-a[x];
			x++;
			
		
		z=max(y-x+1,z);
	}
	cout<<z<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 