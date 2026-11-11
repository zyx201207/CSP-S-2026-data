#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000100],t1,t2,ans;
void migrate(int x,int y,int z){
	if(x==y){
		if(t1>z){
			t1=z;
			t2=1;
		}
		else if(t1==z)t2++;
		return;
	}
	for(int i=x+1;i<=y;i++){
		if(a[i]-a[x]<=d)migrate(i,y,z+1);
		else i=y;
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		ans=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++)cin>>a[j];
		for(int j=1;j<=n;j++){
			for(int k=1;k<j;k++){
				t1=INT_MAX;t2=0;
				migrate(k,j,0);
				if(t2==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

