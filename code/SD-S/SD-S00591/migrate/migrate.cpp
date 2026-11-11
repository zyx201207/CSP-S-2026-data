#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
namespace Rain_Cloud{
	const int N=2e6+7;
	int c,t;
	long long x[N];
	int n;
	long long d;
	int zuo[N];
	long long f[N],kd[N];
	void duoce1(){
		long long ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int pos=1;pos<n-1;pos++){
			long long cnt=0;
			for(int i=1;i<=n;i++){
				f[i]=0x3f3f3f3f;
				kd[i]=0;
				zuo[i]=-1;
			}
			kd[pos]=1;
			int minn=pos;
			for(int i=pos+1;i<=n;i++){
				if(x[i]-x[i-1]>d){
					break;
				}
				while(minn+1<i&&x[i]-x[minn]>d) minn++;
				zuo[i]=minn;
			}
			f[pos]=1;
			kd[pos]=1;
			for(int i=pos+1;i<=n;i++){
				if(f[zuo[i]+2]==f[zuo[i]]) kd[i]=3;
				else if(f[zuo[i]+1]==f[zuo[i]]){
					if(kd[zuo[i]]==1&&kd[zuo[i]+1]==1){
						kd[i]=2;
					}else{
						kd[i]=3;
					}
				}else{
					kd[i]=kd[zuo[i]];
				}
				f[i]=f[zuo[i]]+1;
				cnt=cnt+(kd[i]==2);
			}
			ans=ans+cnt;
		}
		cout<<ans<<'\n';
	}
	void duoce2(){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		cout<<0<<'\n';
	}
	void duoce3(){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n==1){
			cout<<0<<'\n';
		}else{
			long long ans=0;
			long long blk=0,gongcha=x[2]-x[1];
			if(gongcha>d){
				cout<<0<<'\n';
			}else{
				blk=d/gongcha;
				if(blk<2){
					cout<<0<<'\n';
					return ;
				}
				for(int i=1;i<=n;i++){
					if(n-i>=blk+blk-1){
						ans++;
					}
				}
				cout<<ans<<'\n';
			}
		}
	}
	void RainS(){
		cin>>c>>t;
		if(c<=10){
			while(t--) duoce1();
		}else if(c==13||c==14){
			while(t--) duoce2();
		}else if(c==11||c==12){
			while(t--) duoce3();
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	Rain_Cloud::RainS();
	return 0;
}
