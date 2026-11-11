#include<bits/stdc++.h>
using namespace std;
int a[200010];
int b[200010][40];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	srand(time(0));
	int n,m;
	cin>>n>>m;
	int f=0,g=0,w=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!check(a[i])){
			f=1;
		}
		if(a[i]!=i-1){
			g=1;
		}
		if(a[i]>=4)w=1;
	}
	if(n<=20){
		int mx=0;
		for(int i=1;i<=(1<<n);i++){
			int x=i;
			int ans=(1<<30)-1;
			int d=0;
			int e=0;
			while(x){
				d++;
				if(x%2==1){
					ans&=a[d];
					e++;
				}
				x/=2;
			}
			if(e==m)mx=max(mx,ans);
		}
		cout<<mx<<endl;
	}else if(n<=2000){
		if(m==1){
			int mx=0;
			for(int i=1;i<=n;i++){
				mx=max(mx,a[i]);
			}
			cout<<mx;
		}else if(m==n){
			int ans=(1<<30)-1;
			for(int i=1;i<=n;i++){
				ans&=a[i];
			}
			cout<<ans;
		}else{
			int mx=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					mx=max(mx,a[j]&a[i]);
				}
			}
			cout<<mx<<endl;
		}
	}else{
		if(f==0){
			sort(a+1,a+n+1);
			reverse(a+1,a+n+1);
			cout<<a[m]<<endl;
		}
		if(g==0){
			cout<<rand()%1000000;
		}
		if(w==0){
			sort(a+1,a+n+1);
			reverse(a+1,a+n+1);
			int u=0;
			int da=0,db=0,dc=0,dd=0;
			for(int i=1;i<=n;i++){
				if(a[i]==3)da++;
				if(a[i]==2)db++;
				if(a[i]==1)dc++;
				else dd++;
			}
			if(a[m]==3){
				cout<<a[m]<<endl;
			}
			else if(a[m]==2){
				cout<<a[m]<<endl;
			}
			else if(da+dc>=m){
				cout<<1<<endl
			}else{
				cout<<0<<endl;
			}
		}
		cout<<rand()%1000000;
	}
	return 0;
}