#include <bits/stdc++.h>
using namespace std;
const int N=5e5;
const int M=1e8;
int n,m,a[N],d[N];;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int minn=N,x;
	for(int i=1;i<n;i++){
		d[i]=a[i]-a[i-1];
		//cout<<d[i];
		if(d[i]<minn){
			minn=d[i];
			x=i-1;
		}
	}//cout<<minn<<'\0';
	int ans=0,num=1,y=x;
	//cout<<y<<'\0';
	for(int i=x;i<n;i++){
		if(m==0)break;
		if(y==0||((a[x+1]-a[x])<(a[y]-a[y-1]))){
			while(a[x]!=a[x+1]&&m!=0){
				a[x]++;
				m-=num;
			}
			if(a[x]==a[x+1]){
				ans++;
				num++;
				x++;
				//cout<<ans<<'\0';
				//cout<<num<<'\0';
			}
		}else{
			while(a[y-1]!=a[y]&&m!=0){
				a[y-1]++;
				m--;
			}
			if(a[y-1]==a[y]){
				num++;
				ans++;
				y--;
				//cout<<ans<<'\0';
				//cout<<num<<'\0';
				//cout<<m<<'\0';
			}
		}
	}
	if(ans>0)ans++;
	cout<<ans;
	return 0;
}