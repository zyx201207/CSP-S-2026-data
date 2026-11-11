#include<bits/stdc++.h>
using namespace std;
int c,t,n,ans,cnt,flag,minn=999999999;
long long d,x[2000005],cha[2000005];
void a(int i,int j){
	if(i==j){
		if(flag==minn) cnt++;
		else if(flag<minn){
			cnt=1;
			minn=flag;
		}
	}
	for(int k=i+1;k<=j;k++){
		flag++;
		if(x[k]-x[i]<=d){
			a(k,j);
		}
	}
	flag--;
}
int main()
{
	freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--){
    	cin >> n >> d;
    	for(int i=1;i<=n;i++){
    		cin >> x[i];
    		cha[i-1]=x[i]-x[i-1];
		}
		if(d==1) cout << 0 << endl;
		else{
			for(int i=1;i<=n;i++){
				for(int j=i+2;j<=n;j++){
					if(cha[j-1]>d) break;
					cnt=0,flag=0,minn=999999999;
					a(i,j);
					if(cnt==2) ans++;
				}
			}
			cout << ans << endl;
			ans=0;
		}
	}
	return 0;
}

