#include <bits/stdc++.h> 
using namespace std;
const int N=1e6+3;
int n,m;
int a[N],vis[N];
int main(){
	freopen("crystal1.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int maxa=-0x3f3f3f3f;
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxa=max(a[i],maxa);
		vis[a[i]]++;
	}
	sort(a,a+n+1);
	int vmax=0,num=0;
	for(int i=0;i<maxa;i++){
		if(vis[i]>vmax){
			vmax=max(vmax,vis[i]);
			num=i;
		}
	}
	//cout<<vmax;
	int z=a[n/2],ans=0;
	if(num==z){
		for(int i=num;i>=0;i--){
			if(a[i]<num){
				int c=num-a[i];
				if(m-c>=0){
					m-=c;
					ans++;
					cout<<m<<' '<<c<<endl;
				}
			}
		}
		cout<<ans+vmax-1;
		//return 0;
	}
	else if(num>1){
		for(int i=vmax;i>=0;i--){
			int c=num-a[i];
			if(m-c>=0){
				m-=c;
				ans++;
			}
		}
		cout<<ans+vmax;
		//return 0;
	}
	else{
		int c=m/(a[2]-a[1]);
		//cout<<m<<endl;
		//cout<<a[2]<<endl;
		for(int i=0;i<N;i++){
			if(c-i>=0){
				c-=i;
				ans++;
				//cout<<c<<endl;
			}
		}
		cout<<ans;
	}
	//cout<<ans;
	return 0;
}
