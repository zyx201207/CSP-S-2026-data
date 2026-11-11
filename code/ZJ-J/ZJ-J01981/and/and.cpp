#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=-1,sum;
string a2[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int c;
		cin>>c;
		int s=c,y;
		while(s){
			y=s;
			s/=2;
			y%=2;
			a2[i]+=(y+'0');
		}
		for(int j=a2[i].size()-1;j>=0;j--){
			a[i]=a[i]*10+(a2[i][j]-'0');
		}
	}
	for(int i=1;i<=n;i++){
		int x=a[i] and a[i+1];
		for(int j=i+2;j<=i+m;j++){
			x=x and a[j];
		}
		int q=1;
		while(x){
			sum=sum*10+(x%10)*q;
			q*=2;
			x/=10;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
