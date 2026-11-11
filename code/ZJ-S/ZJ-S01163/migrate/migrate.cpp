#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,a[2000005]={0},d,road[2000005],ans=0;
bool l=true;
void solve1(){
	road[1]=0,road[2]=1;
	for(int i=3;i<=n;i++){
		int h=0;
		for(int j=1;j<i;j++){
			if(road[j]+1<road[i])road[i]=road[j]+1;
			else if(road[j]+1==road[i]){
					h++;
			}
		}
		if(h==1)ans++;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		l=true;
		cin>>n>>d;
		ans=0;
		road[2000005]={10000000};
		a[2000005]={0};
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>2&&(a[i]-a[i-1])!=(a[i-1]-a[i-2]))l=false;
		}
		solve1(); 
		if(l==true){
			if(d<2*(a[3]-a[2])){
				cout<<0<<endl;
			}else{
				cout<<ans<<endl;
			}
		}else{
			cout<<1<<endl;
		}
	}
	return 0;
}
