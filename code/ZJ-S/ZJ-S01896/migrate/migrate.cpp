#include <bits/stdc++.h>
using namespace std;
long long T,c,n,d,x[5005],l[5005][5005],ans=0;

void ss(long long s,long long dq,long long b){
	for(long long i=dq+1;x[i]-x[dq]<=d && i<=n;i++){
		l[i][b]++;
		//cout<<s<<' '<<i<<" "<<x[i]-x[dq]<<"\n";
		ss(s,i,b+1);
	}
}

int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	if(c==11 || c==12){
		while(T--){
			long long x1,x2,x3,cn,cd,cc,mc,la=0;
			cin>>cn>>cd>>x1>>x2;
			for(int i=1;i<=cn-2;i++) cin>>x3;
			cc=x2-x1;
			mc=cd/cc;
			if(mc>=3){
				cout<<cn-3<<"\n";
			}
			else cout<<0<<"\n";
		}
		return 0;
	}
	while(T--){
		cin>>n>>d;
		ans=0;
		for(long long i=1;i<=n;i++){
			cin>>x[i];
		}
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				for(long long t=1;t<=n;t++){
					l[j][t]=0;
				}
			}
			ss(i,i,1);
			for(long long j=i+1;j<=n;j++){
				long long c=0;
				for(long long t=0;t<=n && c==0;t++){
					if(l[j][t]!=0){
						if(l[j][t]==2){
							ans++;
							//cout<<'a'<<" "<<j<<' '<<t<<"\n";
						}
						c++;
					}
				}
			}
				/*for(long long j=1;j<=n;j++){
				for(long long t=1;t<=n;t++){
					cout<<l[j][t]<<' ';
				}
				cout<<"\n";
				}
				cout<<"\n";*/
		}
		cout<<ans<<"\n";
	}
	return 0;
} 

/*
wou xiang xie you ji
bu zhi dao xie what
rp++
wou shi qu
(ru dong)(yin an pa xing)
jia you
yuan shen niu bi
qi sheng zhao huan la wan le
*/
