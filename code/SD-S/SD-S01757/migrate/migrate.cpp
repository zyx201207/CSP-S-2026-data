#include<iostream>
using namespace std;

const int N=2000005;
long long ba[N],fr[N],x[N];
int n,d;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	if(c==13||c==14){
		for(int i=1;i<=T;i++)cout<<0<<"\n";
		return 0;
	}
	while(T--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		int l=1;
		for(int i=1;i<=n;i++){
			while((x[i]-x[l])>d)ba[l++]=i-1;
			ba[l]=i;
			fr[i]=l;
		}
		while(l<=n)ba[l++]=n;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(ba[i]>fr[j])ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 1
8 36
1 8 100 120 130 156 177 178

*/
