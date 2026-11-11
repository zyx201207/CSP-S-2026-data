# include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000100],l;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>c>>t;
	for(int k=1;k<=t;k++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==0||c==11||c==12){
			l=x[2]-x[1];
			if(d<l*2||n==1||n==2||n==3) cout<<0<<endl;
			else{
				if(d/l*2<=n) cout<<n-d/l*2+1<<endl;
				else cout<<0<<endl;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
