#include<bits/stdc++.h>
using namespace std;
int c,t;
long long a[2000005];
long long b[2000005];
int js;
int cs;
int n;
int minn=2147483647;
long long d;
void qx(int x,int y){
	if(x==y){
		if(cs<minn){
			minn=cs;
			js=1;
		}else if(cs==minn){
			js++;
		}
		return;
	}
	long long f=b[x];
	int g=1;
	while(f<=d&&x+g<=y){
		cs++;
	    qx(x+g,y);
	    f+=b[x+g];
	    g++;
	    cs--;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		for(int j=1;j<n;j++){
			b[j]=a[j+1]-a[j];
		}
		int e=0;
		for(int j=1;j<n;j++){
			for(int k=j+1;k<=n;k++){
				minn=2147483647;
				js=0;
				cs=0;
				qx(j,k);
				if(js==2){
					e++;
				}
			}
		}
		cout<<e<<endl;
	}
	return 0;
}
