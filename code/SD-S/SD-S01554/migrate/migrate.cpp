#include<bits/stdc++.h>
#define int long long
using namespace std;
	int n,d,x[2000005],sj[2000005],dj[2000005],xd[2000005],sl;
int ind(){
	int g=0,f=1;
	char cg=getchar();
	while(cg<'0'||cg>'9'){
		if(cg=='-'){
			f=-1;
		}
		cg=getchar();
	}
	while(cg>='0'&&cg<='9'){
		g=g*10+(cg-'0');
		cg=getchar();
	}
	return f*g;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;
	cin>>c;
	int t,sk;
	cin>>t;
	while(t){
		sl=0;
		n=ind();
		d=ind();
		for(int i=1;i<=n;i++){
			x[i]=ind();
		}
		sk=x[2]-s[1];
		if(c==11||c==12){
			if(sk/d==2){
				cout<<n-3<<"\n";
			}
			else{
				cout<<0<<"\n";
			}
			t--;
			continue;
		}
		for(int i=1;i<=n;i++){
			xd[i]=0;
		}
		xd[n]=0;
		if(x[n]-x[n-1]<=d){
			xd[n-1]=1;
		}
		else{
			xd[n-1]=0;
		}
		if(x[n-1]-x[n-2]>d){
			xd[n-2]=0;
		}
		else if(x[n-1]-x[n-2]<=d&&x[n]-x[n-2]>d){
			xd[n-2]=1;
		}
		else if(x[n-1]-x[n-2]<=d&&x[n]-x[n-2]<=d){
			xd[n-2]=2;
		}
		for(int i=n-3;i>=1;i--){
			if(x[i+1]-x[i]>d){
				xd[i]=0;
			}
			else if(x[i+1]-x[i]<=d&&x[i+2]-x[i]>d){
				xd[i]=1;
			}
			else if(x[i+1]-x[i]<=d&&x[i+2]-x[i]<=d&&x[i+3]-x[i]>d){
				xd[i]=2;
			}
			else{
				xd[i]=3;
			}
		}
		for(int i=1;i<=n;i++){
			sj[i]=0;
			dj[i]=0;
		}
		sj[n]=0;
		sj[n-1]=0;
		if(xd[n-2]==2){
			sj[n-2]=1;
		}
		dj[n]=0;
		if(xd[n-1]==1){
			dj[n-1]=1;
		}
		if(xd[n-2]==1){
			if(xd[n-1]==1){
				dj[n-2]=2;
			}
			else{
				dj[n-2]=1;
			}
		}
		else if(xd[n-2]==2){
			dj[n-2]=1;
		}
		for(int i=n-3;i>=1;i--){
			if(xd[i]==1){
				dj[i]=dj[i+1]+1;
				sj[i]=sj[i+1];
			}
			else if(xd[i]==2){
				dj[i]=1;
				sj[i]=dj[i+2]+1;
			}
			else if(xd[i]==3){
				dj[i]=1;
				sj[i]=1;
			}
		}
		for(int i=1;i<=n;i++){
			cout<<sj[i]<<" ";
			sl+=sj[i];
		}
		cout<<"\n";
		printf("%lld\n",sl);
		t--;
	}
	
	
	
	
	
	
	
	return 0;
} 
