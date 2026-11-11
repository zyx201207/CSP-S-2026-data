# include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000100],dp[10000][10000],k,ma,b[2001000],h,m,f[2000100];
long long sum,cnt,a,abcd=0;
bool f1=true;
bool f2=true;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int w=1;w<=t;w++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			for(int j=1;j<=i;j++){
				dp[j][i]=x[i]-x[j];
			}
			if(i>2){
				if(x[i]-x[i-1]!=x[i-1]-x[i-2]){
					f1=false;
				}
			}
		}
		if(dp[1][n]<=d){
			cout<<0;
		}
		if(f1==true){
			k=x[2]-x[1];
			long long a=d/k;
			if(a==1){
				cout<<0<<endl;
			}
			else{
				ma=max(abcd,n-1-a);
				cout<<ma<<endl;
			}	
		}
		if(f1==false){
			for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				if(dp[i][j]%d==0){
					break;
				}
				m=i;
				h=1;
				while(1){
					b[h]=dp[m][m+1];
					h++;
					m++;
					if(m>j){
						break;
					}
				}
				for(int e=1;e<=h;e++){
					if(e>1&&b[e]+b[e+1]>d&&b[e]+b[e-1]>d){
						f[e]=0;
					}
				}
				for(int e=1;e<=h;e++){
					if(f[e]==0){
						b[e]==0;
					}
					sum+=b[e];
					if(sum%d==0){
						f2=false;
						break;
					}
				}
				if(f2==false){
					break;
				}
				else{
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
		}
			
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
